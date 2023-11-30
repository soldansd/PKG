#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include "opencv2/opencv.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


enum StructingElement
{
    Square,
    RectVertical,
    RectHorizontal,
    Cross
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void chooseFileSlot();

    void addConstantSlot();
    void negativeSlot();
    void mulConstantSlot();
    void degreeSlot();
    void logarithmSlot();
    void addSlot();
    void mulSlot();
    void linearContrastSlot();

    void erosionSlot();
    void dilatationSlot();
    void trippingSlot();
    void lockingSlot();

    void squareSlot();
    void rectHorizontalSlot();
    void rectVerticalSlot();
    void crossSlot();

private:
    Ui::MainWindow *ui;
    QLabel* originalImageLabel;
    QLabel* processingImageLabel;
    QPixmap* imagePixmap;
    cv::Mat imageMat;
    QString imagePath = ":/rec/images/lake.jpg";
    StructingElement structuringElement = StructingElement::Square;

    cv::Mat QImageToCvMat(const QImage& image);
    cv::Mat getStructuringEl();
};
#endif // MAINWINDOW_H
