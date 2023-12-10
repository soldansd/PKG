#include "plotarea.h"
#include <QPainter>
#include <QPainterPath>
#include <QMessageBox>
#include <QMouseEvent>

PlotArea::PlotArea(QWidget *parent):QWidget(parent),
    AksonometricMatrix(Matrix::GetAksonometricMatrix(angleX, angleY, angleZ)), TransformationMatrix(Matrix::GetIdentityMatrix()),
    ProjectionMatrix(Matrix::GetIdentityMatrix())
{
    u = std::min(width(), height()) / 20;
    recalculateAxis();
}

void PlotArea::SetRotatable(bool newRotatable)
{
    isRotatable = newRotatable;
}
void PlotArea::recalculateAxis()
{
    axis = Matrix::DecomposeToPoints(AksonometricMatrix * Matrix::ComposeFromPoints({Point(1, 0, 0), Point(0, 1, 0), Point(0, 0, 1)}));
}
QPointF PlotArea::Adjust(const Point& _p)
{
    QPointF p = axis[0].toQPoint() * _p.getParameter(0) + axis[1].toQPoint() * _p.getParameter(1) + axis[2].toQPoint() * _p.getParameter(2);

    return QPointF(zx + p.x() * u, zy - p.y() * u);
}
void PlotArea::drawBox(QPainter& p)
{
    int h = height() - 2 * boxOffset;
    int w = width() - 2 * boxOffset;
    QPen boxPen(boxColor);
    boxPen.setWidth(boxWidth);
    p.setPen(boxPen);
    p.drawRect(boxOffset, boxOffset, w, h);
}
void PlotArea::drawGrid(QPainter& p)
{
    QPen gridPen(gridColor);
    gridPen.setWidth(gridLineWidth);
    p.setPen(gridPen);
    int i = 0;
    while(zx + i * u <= width() - boxOffset)
    {
        i++;
        p.drawLine(zx + i * u, boxOffset, zx + i * u, height() - boxOffset);
        p.drawLine(zx - i * u, boxOffset, zx - i * u, height() - boxOffset);
    }
    i = 0;
    while(zy + i * u < height())
    {
        i++;
        p.drawLine(boxOffset, zy + i * u, width() - boxOffset, zy + i * u);
        p.drawLine(boxOffset, zy - i * u, width() - boxOffset, zy - i * u);
    }
}
void PlotArea::drawAxis(QPainter& p)
{
    QPointF center(zx, zy);


    QPen axisPen(XColor);
    axisPen.setWidth(axisWidth);

    p.setPen(axisPen);
    p.drawLine(Adjust(Point(-axisLength, 0, 0)), Adjust(Point(axisLength, 0, 0)));

    axisPen.setColor(YColor);
    p.setPen(axisPen);
    p.drawLine(Adjust(Point(0, -axisLength, 0)), Adjust(Point(0, axisLength, 0)));

    axisPen.setColor(ZColor);
    p.setPen(axisPen);
    p.drawLine(Adjust(Point(0, 0, -axisLength)), Adjust(Point(0, 0, axisLength)));

    axisPen.setColor(axisColor);
    p.setPen(axisPen);
    p.drawLine(center, Adjust({1, 0, 0}));
    p.drawLine(center, Adjust({0, 1, 0}));
    p.drawLine(center, Adjust({0, 0, 1}));

}
void PlotArea::drawTicks(QPainter& p)
{
    QPen ticksPen(axisColor);
    ticksPen.setWidth(axisWidth);
    p.setPen(ticksPen);
    QFont font = p.font();
    font.setPixelSize(12);
    p.setFont(font);

    int alignFlags = Qt::AlignRight | Qt::AlignTop;
    p.drawText(QRect{zx  - u + pixelWidth, zy + pixelWidth, u - pixelWidth, u - pixelWidth}, alignFlags, QString::number(0));
    for (int i = 1; i <= axisLength; ++i)
    {
        p.drawLine(Adjust(Point(i, 0, -tickLength / 2)), Adjust(Point(i, 0, tickLength / 2)));
        p.drawLine(Adjust(Point(-i, 0, -tickLength / 2)), Adjust(Point(-i, 0, tickLength / 2)));
    }

    for (int i = 1; i <= axisLength; ++i)
    {
        p.drawLine(Adjust(Point(0, i, -tickLength / 2)), Adjust(Point(0, i, tickLength / 2)));
        p.drawLine(Adjust(Point(0, -i, -tickLength / 2)), Adjust(Point(0, -i, tickLength / 2)));
    }

    for (int i = 1; i <= axisLength; ++i)
    {
        p.drawLine(Adjust(Point(-tickLength / 2, 0, i)), Adjust(Point(tickLength / 2, 0, i)));
        p.drawLine(Adjust(Point(-tickLength / 2, 0, -i)), Adjust(Point(tickLength / 2, 0, -i)));
    }
}
void PlotArea::drawArrows(QPainter& p)
{
    QPen arrowsPen(axisColor);
    arrowsPen.setWidth((axisWidth));
    p.setBrush(QBrush(axisColor));
    p.setRenderHint(QPainter::RenderHint::Antialiasing);

    QPainterPath px;
    px.moveTo(Adjust(Point(axisLength, 0, -tickLength / 2)));
    px.lineTo(Adjust(Point(axisLength + 1, 0, 0)));
    px.lineTo(Adjust(Point(axisLength, 0, tickLength / 2)));
    px.lineTo(Adjust(Point(axisLength, 0, -tickLength / 2)));
    p.drawPath(px);
    p.drawText(Adjust(Point(axisLength + 1.5, 1, 0)), "X");

    QPainterPath py;
    py.moveTo(Adjust(Point(0, axisLength, -tickLength / 2)));
    py.lineTo(Adjust(Point(0, axisLength + 1, 0)));
    py.lineTo(Adjust(Point(0, axisLength, tickLength / 2)));
    py.lineTo(Adjust(Point(0, axisLength, -tickLength / 2)));
    p.drawPath(py);
    p.drawText(Adjust(Point(0, axisLength + 1.5, 0)), "Y");

    QPainterPath pz;
    pz.moveTo(Adjust(Point(-tickLength / 2, 0, axisLength)));
    pz.lineTo(Adjust(Point(0, 0, axisLength + 1)));
    pz.lineTo(Adjust(Point(tickLength / 2, 0, axisLength)));
    pz.lineTo(Adjust(Point(-tickLength / 2, 0, axisLength)));
    p.drawPath(pz);
    p.drawText(Adjust(Point(0, 1, axisLength + 1.5)), "Z");
}

void PlotArea::drawFigure(QPainter& p)
{
    if (!figure.empty())
    {
        std::vector<Point> toDraw = Matrix::DecomposeToPoints(ProjectionMatrix * TransformationMatrix * Matrix::ComposeFromPoints(figure));
        QPainterPath ph1;
        QPainterPath ph2;
        p.setPen(QPen(Qt::black, lineWidth));
        p.setBrush(Qt::NoBrush);
        int shift = toDraw.size() / 2;
        ph1.moveTo(Adjust(toDraw[0]));
        ph2.moveTo(Adjust(toDraw[shift]));
        p.drawLine(Adjust(toDraw[0]), Adjust(toDraw[0 + shift]));
        for (size_t i = 1; i < toDraw.size() / 2; ++i)
        {
            ph1.lineTo(Adjust(toDraw[i]));
            ph2.lineTo(Adjust(toDraw[i + shift]));
            p.drawLine(Adjust(toDraw[i]), Adjust(toDraw[i + shift]));
        }
        p.drawPath(ph1);
        p.drawPath(ph2);
    }
}

void PlotArea::TransformFigure(Matrix const& transform)
{
    TransformationMatrix = transform * TransformationMatrix;
}

void PlotArea::ProjectFigure(Matrix::ProjectionType type)
{
    ProjectionMatrix = Matrix::GetProjectionMatrix(type);
}

void PlotArea::RevertProjection()
{
    ProjectionMatrix = Matrix::GetIdentityMatrix();
}

void PlotArea::ResetTransform()
{
    TransformationMatrix = Matrix::GetIdentityMatrix();
}

Matrix PlotArea::GetTransformationMatrix() const
{
    return ProjectionMatrix * TransformationMatrix;
}

void PlotArea::SetFigurePoints(const std::vector<Point>& data)
{
    figure = data;
}

void PlotArea::Clear()
{
    figure.clear();
}

void PlotArea::paintEvent(QPaintEvent*)
{
    zx = width() / 2;
    zy = height() / 2;
    AksonometricMatrix = Matrix::GetAksonometricMatrix(angleX, angleY, angleZ);
    recalculateAxis();
    QPainter pt(this);
    drawBox(pt);
    drawAxis(pt);
    drawTicks(pt);
    drawArrows(pt);
    drawFigure(pt);
}

void PlotArea::mousePressEvent(QMouseEvent* event)
{
    lastMousePos = event->position();
    mousePressed = true;
}

void PlotArea::mouseMoveEvent(QMouseEvent* event)
{
    if (mousePressed && isRotatable)
    {
        QPointF pos = event->position();
        double deltaX = pos.x() - lastMousePos.x();
        double deltaY = pos.y() - lastMousePos.y();
        angleY += angleShift * deltaX;
        angleX += angleShift * deltaY;
        lastMousePos = pos;
        repaint();
    }
}

void PlotArea::SetRotation(double _angleX, double _angleY, double _angleZ)
{
    angleX = _angleX;
    angleY = _angleY;
    angleZ = _angleZ;
}

void PlotArea::mouseReleaseEvent(QMouseEvent*)
{
    mousePressed = false;
}

void PlotArea::wheelEvent(QWheelEvent* event)
{

    SetUnit(u + deltaUnit * (2 * (event->angleDelta().y() > 0) - 1));
    repaint();
}

int PlotArea::getUnit() const
{
    return u;
}

void PlotArea::SetUnit(int nu)
{
    if (nu >= minUnit && nu <= maxUnit)
    {
        u = nu;
    }
}
