#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coordinatesystem.h"
#include "infoaboutalgorithm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum class CurrentAlgorithm
{
    None,
    BresenhamLine,
    BresenhamCircle,
    NaiveLine,
    DDALine,
    WuLine,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
private slots:

    void on_drawButton_clicked();

    void on_NaiveLine_clicked();

    void on_BresenhamLine_clicked();

    void on_BresenhamCircle_clicked();

    void on_DDALine_clicked();

    void on_WuLine_clicked();

    void on_unitButton_clicked();

private:
    void DisableInput();
    void EnableInputLine();
    void EnableInputCircle();
    void BresenhamLine(int x1, int y1, int x2, int y2);
    void BresenhamCircle(int x1, int y1, int radius);
    void DDALine(int x1, int y1, int x2, int y2);
    void NaiveLine(int x1, int y1, int x2, int y2);
    void WuLine(int x1, int y1, int x2, int y2);
    QString pointF(qreal x, qreal y);
    QString point(int x, int y);
    QString pointWu(int x, int y, qreal percent);
    Ui::MainWindow* ui;
    CoordinateSystem* coordinateSystem = nullptr;
    InfoAboutAlgorithm* infoAboutAlgorithm = nullptr;
    CurrentAlgorithm currentAlgorithm = CurrentAlgorithm::None;
};
#endif // MAINWINDOW_H
