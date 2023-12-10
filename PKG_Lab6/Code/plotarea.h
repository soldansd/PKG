#ifndef PLOTAREA_H
#define PLOTAREA_H

#include <QPainter>
#include <QWidget>
#include <vector>
#include "matrix.h"

class PlotArea : public QWidget
{
    Q_OBJECT
public:
    explicit PlotArea(QWidget *parent = nullptr);
    void SetFigurePoints(const std::vector<Point>& data);
    void TransformFigure(Matrix const& transform);
    void ProjectFigure(Matrix::ProjectionType type);
    void RevertProjection();
    void ResetTransform();
    void SetRotatable(bool newRotatable);
    void SetRotation(double _angleX, double _angleY, double _angleZ);
    Matrix GetTransformationMatrix() const;
    QPointF Adjust(const Point& p);
    void Clear();
    void SetUnit(int nu);
    int getUnit() const;
private:
    bool isRotatable = true;
    bool mousePressed = false;
    QPointF lastMousePos;
    double angleX = 19.47 / 180 * 3.14;
    double angleY = -20.7 / 180 * 3.14;
    double angleZ = 0;
    double angleShift = 0.005;
    std::vector<Point> axis;
    Matrix AksonometricMatrix, TransformationMatrix, ProjectionMatrix;
    int u;
    int minUnit = 5;
    int maxUnit = 40;
    int deltaUnit = 1;
    double tickLength = 1;
    int gridLineWidth = 1;
    int axisWidth = 2;
    int boxOffset = 1;
    int boxWidth = 1;
    int pixelWidth = 1;
    int lineWidth = 3;
    int axisLength = 20;
    int zx = 0;
    int zy = 0;
    std::vector<Point> figure;
    QColor XColor = Qt::blue;
    QColor YColor = Qt::green;
    QColor ZColor = Qt::magenta;
    QColor gridColor = Qt::gray;
    QColor axisColor = Qt::black;
    QColor boxColor = Qt::gray;
    void recalculateAxis();
    void inline drawBox(QPainter(&p));
    void inline drawGrid(QPainter& p);
    void inline drawAxis(QPainter& p);
    void inline drawTicks(QPainter& p);
    void inline drawArrows(QPainter& p);
    void inline drawFigure(QPainter& p);
    void paintEvent(QPaintEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void wheelEvent(QWheelEvent* event) override;
};

#endif // PLOTAREA_H
