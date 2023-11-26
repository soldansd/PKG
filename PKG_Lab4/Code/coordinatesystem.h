#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QWidget>

class CoordinateSystem : public QWidget
{
    Q_OBJECT
public:
    explicit CoordinateSystem(QWidget *parent = nullptr);
    void addPixel(int x, int y, qreal percent = 1);
    void setUnitSegmentInPexels(int unit);
    int getUnitSegmentInPexels() const;
    void clear();

private:
    std::vector<std::pair<std::pair<int,int>, qreal>> pixels;
    QColor axisColor = Qt::black;
    QColor gridColor = Qt::gray;
    QColor frameColor = Qt::gray;

    int unitSegmentInPixels;
    int notchLength = 4;
    int gridLineWidth = 1;
    int axisWidth = 2;
    int frameShift = 0;
    int frameWidth = 1;
    int textShift = 1;
    int xCenter = 0;
    int yCenter = 0;

    int maxGreySaturation = 200;
    void drawFrame(QPainter& p);
    void drawGrid(QPainter& p);
    void drawAxis(QPainter& p);
    void drawNotches(QPainter& p);
    void drawArrows(QPainter& p);
    void drawPixels(QPainter& p);
    void paintEvent(QPaintEvent* event) override;
};

#endif // COORDINATESYSTEM_H
