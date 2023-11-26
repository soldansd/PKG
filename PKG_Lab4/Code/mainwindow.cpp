#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QValidator>
#include <chrono>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    coordinateSystem = new CoordinateSystem();
    infoAboutAlgorithm = new InfoAboutAlgorithm();
    setStyleSheet("background-color: white;");

    QGridLayout *gridLayout = new QGridLayout;

    gridLayout->addWidget(coordinateSystem, 0, 5, 12, 10);
    gridLayout->addWidget(infoAboutAlgorithm, 0, 0, 12, 5);

    gridLayout->addWidget(ui->NaiveLine, 13, 0, 1, 4);
    gridLayout->addWidget(ui->DDALine,  14, 0, 1, 4);
    gridLayout->addWidget(ui->BresenhamLine, 15, 0, 1, 4);
    gridLayout->addWidget(ui->BresenhamCircle, 16, 0, 1, 4);
    gridLayout->addWidget(ui->WuLine,17, 0, 1, 4);

    gridLayout->addWidget(ui->x1Label, 13, 4, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(ui->x1Input, 13, 5, 1, 1);
    gridLayout->addWidget(ui->y1Label, 13, 6, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(ui->y1Input, 13, 7, 1, 1);

    gridLayout->addWidget(ui->x2Label, 15, 4, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(ui->x2Input, 15, 5, 1, 1);
    gridLayout->addWidget(ui->y2Label, 15, 6, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(ui->y2Input, 15, 7, 1, 1);

    gridLayout->addWidget(ui->radiusLabel, 15, 6, 1, 1, Qt::AlignRight);
    gridLayout->addWidget(ui->radiusInput, 15, 7, 1, 1);

    gridLayout->addWidget(ui->drawButton, 13, 11, 1, 2);
    gridLayout->addWidget(ui->unitButton, 15, 11, 1, 2);
    for (int i = 0; i < 8; ++i)
    {
        gridLayout -> setColumnStretch(i, 10);
    }
    for (int i = 0; i < 14; ++i)
    {
        gridLayout -> setRowStretch(i, 10);
    }
    centralWidget()->setLayout(gridLayout);
    setMinimumSize(700, 600);
    resize(800, 750);
    setWindowTitle("Алгоритмы растеризации");
    DisableInput();

    QIntValidator* validator = new QIntValidator(-100, 100, this);
    ui->x1Input->setValidator(validator);
    ui->y1Input->setValidator(validator);
    ui->x2Input->setValidator(validator);
    ui->y2Input->setValidator(validator);
    ui->radiusInput->setValidator(validator);
    ui->x1Input->setText("0");
    ui->y1Input->setText("0");
    ui->x2Input->setText("0");
    ui->y2Input->setText("0");
    ui->radiusInput->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete coordinateSystem;
    delete infoAboutAlgorithm;
}
void MainWindow::DisableInput()
{
    ui-> x1Label->setVisible(false);
    ui-> x1Input->setVisible(false);
    ui-> y1Label->setVisible(false);
    ui-> y1Input->setVisible(false);
    ui-> x2Label->setVisible(false);
    ui-> x2Input->setVisible(false);
    ui-> y2Label->setVisible(false);
    ui-> y2Input->setVisible(false);
    ui->radiusLabel->setVisible(false);
    ui->radiusInput->setVisible(false);
}
void MainWindow::EnableInputLine()
{
    DisableInput();
    ui->x1Label->setVisible(true);
    ui->x1Input->setVisible(true);
    ui->y1Label->setVisible(true);
    ui->y1Input->setVisible(true);
    ui->x2Label->setVisible(true);
    ui->x2Input->setVisible(true);
    ui->y2Label->setVisible(true);
    ui->y2Input->setVisible(true);
}
void MainWindow::EnableInputCircle()
{
    DisableInput();
    ui->x1Label->setVisible(true);
    ui->x1Input->setVisible(true);
    ui->y1Label->setVisible(true);
    ui->y1Input->setVisible(true);
    ui->radiusLabel->setVisible(true);
    ui->radiusInput->setVisible(true);
    ui->x1Input->setText("0");
    ui->y1Input->setText("0");
    ui->radiusInput->setText("0");
}
QString MainWindow::pointF(qreal x, qreal y)
{
    return "(" + QString::number(x) + ", " + QString::number(y) + ")";
}
QString MainWindow::point(int x, int y)
{
    return "(" + QString::number(x) + ", " + QString::number(y) + ")";
}
QString MainWindow::pointWu(int x, int y, qreal percent)
{
    return point(x, y) + ", со значением черного: " + QString::number((int)(100 * percent)) + "%";
}
void MainWindow::NaiveLine(int x1, int y1, int x2, int y2)
{
    infoAboutAlgorithm -> writeLine("Пошаговый алгоритм начал работу.");
    auto begin = std::chrono::steady_clock::now();
    infoAboutAlgorithm -> writeLine("Рисуем линию от " + point(x1, y1) + " до " +
                point(x2, y2));
    coordinateSystem -> clear();
    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    infoAboutAlgorithm -> writeLine("Вычисленный dx = " + QString::number(dx));
    infoAboutAlgorithm -> writeLine("Вычисленный dy = " + QString::number(dy));
    if (dx == 0 && dy == 0)
    {
         infoAboutAlgorithm -> writeLine("dx = 0, dy = 0 => рисуем одну точку " + point(x2, y2));
         coordinateSystem->addPixel(x1, y1);
    }
    else
    {
         if (std::abs(dx) > std::abs(dy))
         {
             infoAboutAlgorithm -> writeLine("|dx| > |dy| => рисуем отрезок, просматривая значения x от " + QString::number(x1) +  " до " + QString::number(x2));
             for(int x = x1; x <= x2; ++x)
             {
                 qreal temp = y1 + dy * (x - x1) / (qreal)dx;
                 infoAboutAlgorithm -> writeLine("Точное значение y для x = " + QString::number(x) + " равно " + QString::number(temp) +
                                      ", рисуем точку " + point(x, temp), 1);
                 coordinateSystem->addPixel(x, (int)temp);
             }
         }
         else
         {
             if (y1 > y2)
             {
                 std::swap(x1, x2);
                 std::swap(y1, y2);
             }
             infoAboutAlgorithm -> writeLine("|dy| >= |dx| => рисуем отрезок, просматривая значения y от " + QString::number(y1) +  " до " + QString::number(y2));
             for (int y = y1; y <= y2; ++y)
             {
                 qreal temp = dx / (qreal)dy * (y - y1) + x1;
                 infoAboutAlgorithm -> writeLine("Точное значение x для y = " + QString::number(y) + " равно " + QString::number(temp) +
                                      ", рисуем точку " + point(temp, y), 1);
                 coordinateSystem->addPixel((int)temp, y);
             }
         }
    }
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    infoAboutAlgorithm -> writeLine("Пошаговый алгоритм закончил работу(" + QString::number(duration) + " ms)");
    infoAboutAlgorithm -> writeSeparator();
}
void MainWindow::BresenhamLine(int x1, int y1, int x2, int y2)
{
    infoAboutAlgorithm -> writeLine("Алгоритм Брезенхема начал работу");
    auto begin = std::chrono::steady_clock::now();
    coordinateSystem -> clear();
    int dx = std::abs(x2 - x1);
    infoAboutAlgorithm -> writeLine("|dx| = " + QString::number(dx));
    int sx = x1 < x2 ? 1 : -1;
    int dy = -std::abs(y2 - y1);
    infoAboutAlgorithm -> writeLine("-|dy| = " + QString::number(dy));
    int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;
    infoAboutAlgorithm -> writeLine("Рисуем линию от " + point(x1, y1) + " до " +
                point(x2, y2));
    infoAboutAlgorithm -> writeLine("Пусть линия задается уравнением f(X, Y) = 0. Будем поддерживать f(Xi, Yi) - f(Xi - 1, Yi - 1) в качестве значения ошибки");
    while (true)
    {
        infoAboutAlgorithm -> writeLine("Рисуем точку " + point(x1, y1));
        coordinateSystem->addPixel(x1, y1);
        infoAboutAlgorithm -> writeLine("error = " + QString::number(error), 1);
        if (x1 == x2 && y1 == y2)
        {
            infoAboutAlgorithm->writeLine("Достигнута точка " + point(x2, y2) + ", выход из цикла", 1);
            break;
        }
        int e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x1 == x2)
            {
                infoAboutAlgorithm->writeLine("Достигнут x1, выход из цикла", 1);
                break;
            }
            infoAboutAlgorithm->writeLine("error - 0.5dy >= 0, значит сдвигаем текущий x на " + QString::number(sx) +
                                 ", значение ошибки уменьшается на " + QString::number(std::abs(dy)), 1);
            error = error + dy;
            x1 = x1 + sx;
        }
        if (e2 <= dx)
        {
            if (y1 == y2)
            {
                infoAboutAlgorithm -> writeLine("Достигнут y1, выход из цикла", 1);
                break;
            }
            infoAboutAlgorithm -> writeLine("error - 0.5dx <= 0, значит сдвигаем текущий y на " + QString::number(sy) +
                                 ", значение ошибки увеличивается на " + QString::number(dx), 1);
            error = error + dx;
            y1 = y1 + sy;
        }
    }
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    infoAboutAlgorithm->writeLine("Алгоритм Брезенхема закончил работу(" + QString::number(duration) + " ms)");
    infoAboutAlgorithm->writeSeparator();
}
void MainWindow::DDALine(int x1, int y1, int x2, int y2)
{
    infoAboutAlgorithm->writeLine("Алгоритм ЦДА начал работу");
    auto begin = std::chrono::steady_clock::now();
    infoAboutAlgorithm->writeLine("Рисуем линию от " + point(x1, y1) + " до " +
                point(x2, y2));
    coordinateSystem->clear();
    qreal dx = (x2 - x1);
    qreal dy = (y2 - y1);
    int step;
    if (abs(dx) >= abs(dy))
      step = abs(dx);
    else
      step = abs(dy);
    dx = dx / step;
    dy = dy / step;
    infoAboutAlgorithm->writeLine("Число шагов = " + QString::number(step));
    infoAboutAlgorithm->writeLine("dx = " + QString::number(dx));
    infoAboutAlgorithm->writeLine("dy = " + QString::number(dy));
    qreal x = x1;
    qreal y = y1;
    int i = 0;
    while (i <= step) {
        infoAboutAlgorithm->writeLine("Вычисленная точка: " + pointF(x, y) +
                             ", рисуем точку " + point(x, y));
        coordinateSystem->addPixel(x, y);
        x = x + dx;
        y = y + dy;
        i++;
    }
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    infoAboutAlgorithm->writeLine("Алгоритм ЦДА закончил работу(" + QString::number(duration) + " ms)");
    infoAboutAlgorithm->writeSeparator();
}
void MainWindow::BresenhamCircle(int x1, int y1, int radius)
{
    infoAboutAlgorithm->writeLine("Алгоритм Брезенхема для окружности начал работу");
    auto begin = std::chrono::steady_clock::now();
    coordinateSystem->clear();
    infoAboutAlgorithm->writeLine("Рисуем окружность с центром в " + point(x1, y1) + " и радиусом " + QString::number(radius));
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    infoAboutAlgorithm->writeLine("Будем поддерживать ошибку радиуса, и в соответствии с ней рисовать точки ближе к центру или дальше от него");
    infoAboutAlgorithm->writeLine("Изначальная ошибка радиуса = " + QString::number(radiusError));
    while (x >= y)
    {
        infoAboutAlgorithm->writeLine("Рисуем точку " + point(x + x1, y + y1) + " и соответствующие симметричные точки во всех октантах");
        coordinateSystem->addPixel(x + x1, y + y1);
        coordinateSystem->addPixel(y + x1, x + y1);
        coordinateSystem->addPixel(-x + x1, y + y1);
        coordinateSystem->addPixel(-y + x1, x + y1);
        coordinateSystem->addPixel(-x + x1, -y + y1);
        coordinateSystem->addPixel(-y + x1, -x + y1);
        coordinateSystem->addPixel(x + x1, -y + y1);
        coordinateSystem->addPixel(y + x1, -x + y1);
        ++y;
        if (radiusError < 0)
        {
            infoAboutAlgorithm -> writeLine("Ошибка радиуса < 0, значит рисуем следующие точки на том же расстоянии", 1);
            infoAboutAlgorithm -> writeLine("Увеличиваем ошибку радиуса на " + QString::number(2 * y + 1), 1);
            radiusError += 2 * y + 1;
        }
        else
        {
            infoAboutAlgorithm -> writeLine("Ошибка радиуса > 0, значит рисуем следующие точки на меньшем расстоянии", 1);
            infoAboutAlgorithm -> writeLine("Изменяем ошибку радиуса на " + QString::number(2 * (y - x + 1)), 1);
            --x;
            radiusError += 2 * (y - x + 1);
        }
    }
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    infoAboutAlgorithm -> writeLine("Алгоритм Брезенхема для окружности закончил работу(" + QString::number(duration) + " ms)");
    infoAboutAlgorithm -> writeSeparator();
}
void MainWindow::WuLine(int x0, int y0, int x1, int y1)
{
    coordinateSystem -> clear();
    auto ipart = [](qreal x)
    {
        return floor(x);
    };

    auto round = [&ipart](qreal x)
    {
        return ipart(x + 0.5);
    };

    auto fpart = [](qreal x)
    {
        return x - floor(x);
    };

    auto rfpart = [&fpart](qreal x)
    {
        return 1 - fpart(x);
    };
    infoAboutAlgorithm -> writeLine("Алгоритм Ву начал работу");
    auto begin = std::chrono::steady_clock::now();
    bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);

    if (steep)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int dx = x1 - x0;
    int dy = y1 - y0;
    infoAboutAlgorithm -> writeLine("dx = " + QString::number(dx));
    infoAboutAlgorithm -> writeLine("dy = " + QString::number(dy));
    qreal gradient;
    if (dx == 0)
        gradient = 1.0;
    else
        gradient = dy / (qreal)dx;
    infoAboutAlgorithm -> writeLine("Вычисляем значение градиента dy / dx: " + QString::number(gradient));

    int xend = round(x0);
    qreal yend = y0 + gradient * (xend - x0);
    qreal xgap = rfpart(x0 + 0.5);
    int xpxl1 = xend;
    int ypxl1 = ipart(yend);

    infoAboutAlgorithm -> writeLine("Обрабатываем первую крайнюю точку");
    if (steep)
    {
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ypxl1, xpxl1, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(ypxl1,   xpxl1, rfpart(yend) * xgap);
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ypxl1 + 1, xpxl1, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(ypxl1 + 1, xpxl1,  fpart(yend) * xgap);
    }
    else
    {
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(xpxl1, ypxl1, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(xpxl1, ypxl1  , rfpart(yend) * xgap);
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(xpxl1, ypxl1 + 1, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(xpxl1, ypxl1+1,  fpart(yend) * xgap);
    }
    qreal intery = yend + gradient;

    xend = round(x1);
    yend = y1 + gradient * (xend - x1);
    xgap = fpart(x1 + 0.5);
    int xpxl2 = xend;
    int ypxl2 = ipart(yend);

    infoAboutAlgorithm -> writeLine("Обрабатываем вторую крайнюю точку");
    if (steep)
    {
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ypxl2, xpxl2, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(ypxl2  , xpxl2, rfpart(yend) * xgap);
        infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ypxl2 + 1, xpxl2, rfpart(yend) * xgap), 1);
        coordinateSystem->addPixel(ypxl2+1, xpxl2,  fpart(yend) * xgap);
    }
    else
    {
        infoAboutAlgorithm -> writeLine("Рисуем точку " + point(xpxl2, ypxl2) + ", со значением черного : " + QString::number(rfpart(yend) * xgap * 100) + "%", 1);
        coordinateSystem->addPixel(xpxl2, ypxl2,  rfpart(yend) * xgap);
        infoAboutAlgorithm -> writeLine("Рисуем точку " + point(xpxl2, ypxl2 + 1) + ", со значением черного : " + QString::number(fpart(yend) * xgap * 100) + "%", 1);
        coordinateSystem->addPixel(xpxl2, ypxl2+1, fpart(yend) * xgap);
    }

    infoAboutAlgorithm -> writeLine("Рисуем все остальные точки");
    if (steep)
    {
        for (int x = xpxl1 + 1; x < xpxl2; ++x)
           {
                coordinateSystem->addPixel(ipart(intery), x, rfpart(intery));
                coordinateSystem->addPixel(ipart(intery) +1 , x,  fpart(intery));
                intery = intery + gradient;
                infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ipart(intery), x, rfpart(intery)), 1);
                infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(ipart(intery) + 1, x, fpart(intery)), 1);
                infoAboutAlgorithm -> writeLine("Пересчитанное значение x: " + QString::number(intery), 2);
           }
    }
    else
    {
        for (int x = xpxl1 + 1; x < xpxl2; ++x)
           {
                coordinateSystem->addPixel(x, ipart(intery),  rfpart(intery));
                coordinateSystem->addPixel(x, ipart(intery)+1, fpart(intery));
                intery = intery + gradient;
                infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(x, ipart(intery),  rfpart(intery)), 1);
                infoAboutAlgorithm -> writeLine("Рисуем точку " + pointWu(x, ipart(intery)+1, fpart(intery)), 1);
                infoAboutAlgorithm -> writeLine("Пересчитанное значение y: " + QString::number(intery), 2);
           }
    }
    auto end = std::chrono::steady_clock::now();
    int duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    infoAboutAlgorithm -> writeLine("Алгоритм Ву закончил работу(" + QString::number(duration) + " ms)");
}


void MainWindow::on_drawButton_clicked()
{
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0, r = 1;
    auto validateField = [](QLineEdit* ed){
        if (ed -> text().isEmpty())
        {
            ed -> setText("0");
        }
    };
    validateField(ui -> x1Input);
    validateField(ui -> y1Input);
    validateField(ui -> x2Input);
    validateField(ui -> y2Input);
    validateField(ui -> radiusInput);
    switch(currentAlgorithm)
    {
        case CurrentAlgorithm::None:
            QMessageBox::warning(centralWidget(), "Ошибка", "Нечего рисовать");
            break;
        case CurrentAlgorithm::BresenhamLine:
            x0 = ui -> x1Input -> text().toInt();
            y0 = ui -> y1Input -> text().toInt();
            x1 = ui -> x2Input -> text().toInt();
            y1 = ui -> y2Input -> text().toInt();
            BresenhamLine(x0, y0, x1, y1);
            break;
        case CurrentAlgorithm::NaiveLine:
            x0 = ui -> x1Input -> text().toInt();
            y0 = ui -> y1Input -> text().toInt();
            x1 = ui -> x2Input -> text().toInt();
            y1 = ui -> y2Input -> text().toInt();
            NaiveLine(x0, y0, x1, y1);
            break;
        case CurrentAlgorithm::DDALine:
            x0 = ui -> x1Input -> text().toInt();
            y0 = ui -> y1Input -> text().toInt();
            x1 = ui -> x2Input -> text().toInt();
            y1 = ui -> y2Input -> text().toInt();
            DDALine(x0, y0, x1, y1);
            break;
        case CurrentAlgorithm::WuLine:
            x0 = ui -> x1Input -> text().toInt();
            y0 = ui -> y1Input -> text().toInt();
            x1 = ui -> x2Input -> text().toInt();
            y1 = ui -> y2Input -> text().toInt();
            WuLine(x0, y0, x1, y1);
            break;
        case CurrentAlgorithm::BresenhamCircle:
            x0 = ui -> x1Input -> text().toInt();
            y0 = ui -> y1Input -> text().toInt();
            r = ui -> radiusInput -> text().toInt();
            BresenhamCircle(x0, y0, r);
            break;
    }
}

void MainWindow::on_NaiveLine_clicked()
{
    coordinateSystem -> clear();
    currentAlgorithm = CurrentAlgorithm::NaiveLine;
    EnableInputLine();
}


void MainWindow::on_BresenhamLine_clicked()
{
    coordinateSystem -> clear();
    currentAlgorithm = CurrentAlgorithm::BresenhamLine;
    EnableInputLine();
}


void MainWindow::on_BresenhamCircle_clicked()
{
    coordinateSystem -> clear();
    currentAlgorithm = CurrentAlgorithm::BresenhamCircle;
    EnableInputCircle();
}


void MainWindow::on_DDALine_clicked()
{
    coordinateSystem -> clear();
    currentAlgorithm = CurrentAlgorithm::DDALine;
    EnableInputLine();
}


void MainWindow::on_WuLine_clicked()
{
    coordinateSystem -> clear();
    currentAlgorithm = CurrentAlgorithm::WuLine;
    EnableInputLine();
}


void MainWindow::on_unitButton_clicked()
{
    int length = std::min(width(), height());
    bool ok;
    int nu = QInputDialog::getInt(centralWidget(), "Изменение параметров", "Введите новое значение единичного отрезка", coordinateSystem -> getUnitSegmentInPexels(), 3, length / 10, 1, &ok);
    if (ok)
    {
        coordinateSystem -> setUnitSegmentInPexels(nu);
        coordinateSystem -> repaint();
    }
}

