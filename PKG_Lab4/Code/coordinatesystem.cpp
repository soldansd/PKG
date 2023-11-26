#include "coordinatesystem.h"
#include <QPainter>
#include <QPainterPath>
#include <QMessageBox>

CoordinateSystem::CoordinateSystem(QWidget *parent):QWidget(parent)
{
    unitSegmentInPixels = std::min(width(), height()) / 20;
    setStyleSheet("background-color: white;");
}

void CoordinateSystem::drawFrame(QPainter& p)
{
    int h = height() - 2 * frameShift;
    int w = width() - 2 * frameShift;
    QPen framePen(frameColor);
    framePen.setWidth(frameWidth);
    p.setPen(framePen);
    p.drawRect(frameShift, frameShift, w, h);
}
void CoordinateSystem::drawGrid(QPainter& p)
{
    QPen gridPen(gridColor);
    gridPen.setWidth(gridLineWidth);
    p.setPen(gridPen);

    for(int i = 0; xCenter + i * unitSegmentInPixels <= width() - frameShift;)
    {
        i++;
        p.drawLine(xCenter + i * unitSegmentInPixels, frameShift, xCenter + i * unitSegmentInPixels, height() - frameShift);
        p.drawLine(xCenter - i * unitSegmentInPixels, frameShift, xCenter - i * unitSegmentInPixels, height() - frameShift);
    }

    for(int i = 0; yCenter + i * unitSegmentInPixels < height();)
    {
        i++;
        p.drawLine(frameShift, yCenter + i * unitSegmentInPixels, width() - frameShift, yCenter + i * unitSegmentInPixels);
        p.drawLine(frameShift, yCenter - i * unitSegmentInPixels, width() - frameShift, yCenter - i * unitSegmentInPixels);
    }
}
void CoordinateSystem::drawAxis(QPainter& p)
{
    QPen axisPen(axisColor);
    axisPen.setWidth(axisWidth);
    p.setPen(axisPen);
    p.drawLine(frameShift, yCenter, width() - frameShift, yCenter);
    p.drawLine(xCenter, frameShift, xCenter, height() - frameShift);
}
void CoordinateSystem::drawNotches(QPainter& p)
{
    QPen notchesPen(axisColor);
    notchesPen.setWidth(axisWidth);
    p.setPen(notchesPen);
    QFont font = p.font();
    font.setPixelSize(12);
    p.setFont(font);
    p.drawText(QRect{xCenter + textShift, yCenter - unitSegmentInPixels + textShift, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(0));

    for(int i = 0; xCenter + (i + 2) * unitSegmentInPixels < width();)
    {
        i++;
        p.drawLine(xCenter + i * unitSegmentInPixels, yCenter + notchLength, xCenter + i * unitSegmentInPixels, yCenter - notchLength);
        p.drawLine(xCenter - i * unitSegmentInPixels, yCenter + notchLength, xCenter - i * unitSegmentInPixels, yCenter - notchLength);
        if (xCenter + (i + 2) * unitSegmentInPixels < width())
            p.drawText(QRect{xCenter + i * unitSegmentInPixels + textShift, yCenter - unitSegmentInPixels + textShift, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(i));
        p.drawText(QRect{xCenter - i * unitSegmentInPixels + textShift, yCenter - unitSegmentInPixels + textShift, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(-i));
    }

    for(int i = 0; yCenter + (i + 2) * unitSegmentInPixels < height();)
    {
        i++;
        p.drawLine(xCenter - notchLength, yCenter + i * unitSegmentInPixels, xCenter + notchLength, yCenter + i * unitSegmentInPixels);
        p.drawLine(xCenter - notchLength, yCenter - i * unitSegmentInPixels, xCenter + notchLength, yCenter - i * unitSegmentInPixels);
        if (yCenter - (i + 2) * unitSegmentInPixels > 0)
            p.drawText(QRect{xCenter + textShift, yCenter - (i + 1) * unitSegmentInPixels +  textShift, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(i));
        p.drawText(QRect{xCenter + textShift, yCenter + (i - 1) * unitSegmentInPixels + textShift, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(-i));
    }
}
void CoordinateSystem::drawArrows(QPainter& p)
{
    QPen arrowsPen(axisColor);
    arrowsPen.setWidth(axisWidth);
    p.setBrush(QBrush(axisColor));
    p.setRenderHint(QPainter::RenderHint::Antialiasing);

    QPainterPath xArrow;
    xArrow.moveTo(width() - unitSegmentInPixels - 1, yCenter + 2 * notchLength);
    xArrow.lineTo(width() - unitSegmentInPixels - 1, yCenter - 2 * notchLength);
    xArrow.lineTo(width() - 1, yCenter);
    xArrow.lineTo(width() - unitSegmentInPixels - 1, yCenter + 2 * notchLength);
    p.drawPath(xArrow);
    p.drawText(QRect{width() - unitSegmentInPixels / 2 - 1, yCenter + unitSegmentInPixels / 2, unitSegmentInPixels, unitSegmentInPixels}, "X");

    QPainterPath yArrow;
    yArrow.moveTo(xCenter + 2 * notchLength, unitSegmentInPixels + 1);
    yArrow.lineTo(xCenter - 2 * notchLength, unitSegmentInPixels + 1);
    yArrow.lineTo(xCenter, 1);
    yArrow.lineTo(xCenter + 2 * notchLength, unitSegmentInPixels + 1);
    p.drawPath(yArrow);
    p.drawText(QRect{xCenter + unitSegmentInPixels / 2, unitSegmentInPixels / 2, unitSegmentInPixels, unitSegmentInPixels}, "Y");
}
void CoordinateSystem::drawPixels(QPainter& p)
{
    for (const auto& data: pixels)
    {
        auto pixel = data.first;
        int greySaturation =  maxGreySaturation * (1 - data.second);
        QColor pixelColor(greySaturation, greySaturation, greySaturation);
        QPen pixelPen(pixelColor, textShift);
        p.setPen(pixelPen);
        p.setBrush(QBrush(pixelColor));
        int xpos = xCenter + (pixel.first) * unitSegmentInPixels + textShift;
        int ypos = yCenter - (pixel.second + 1) * unitSegmentInPixels + textShift;
        p.drawRect(xpos, ypos, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift);
        if (greySaturation < 3 * maxGreySaturation / 4)
        {
            p.setPen(Qt::white);
        }
        else
        {
            p.setPen(Qt::black);
        }
        if (pixel.second == 0)
        {
            p.drawText(QRect{xpos, ypos, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(pixel.first));
        }
        else if (pixel.first == 0)
        {
            p.drawText(QRect{xpos, ypos, unitSegmentInPixels - textShift, unitSegmentInPixels - textShift}, Qt::AlignLeft | Qt::AlignBottom, QString::number(pixel.second));
        }
    }
}
void CoordinateSystem::addPixel(int x, int y, qreal percent)
{
    pixels.push_back({{x, y}, percent});
    repaint();
}
void CoordinateSystem::clear()
{
    pixels.clear();
    repaint();
}
void CoordinateSystem::setUnitSegmentInPexels(int unit)
{
    unitSegmentInPixels = unit;
}
void CoordinateSystem::paintEvent(QPaintEvent*)
{
    xCenter = width() / 2;
    yCenter = height() / 2;
    QPainter pt(this);
    drawFrame(pt);
    drawGrid(pt);
    drawAxis(pt);
    drawNotches(pt);
    drawArrows(pt);
    drawPixels(pt);
}
int CoordinateSystem::getUnitSegmentInPexels() const
{
    return unitSegmentInPixels;
}
