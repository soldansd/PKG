#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QPixmap>
#include <QInputDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* menuFile = new QMenu("Файл");
    QAction* chooseFile = new QAction("Выбрать...");
    menuFile->addAction(chooseFile);
    connect(chooseFile, SIGNAL(triggered(bool)), this, SLOT(chooseFileSlot()));

    QMenu* menuElementWiseOperations = new QMenu("Поэлементные операции и ЛК");
    QAction* addConstant = new QAction("Добавить константу...");
    QAction* negative = new QAction("Негатив");
    QAction* mulConstant = new QAction("Умножить на константу...");
    QAction* degree = new QAction("Степенное преобразование...");
    QAction* logarithm = new QAction("Логарифмическое преобразование");
    QAction* add = new QAction("Сложение");
    QAction* mul = new QAction("Умножение");
    QAction* linearContrast = new QAction("Линейное контрастирование");
    menuElementWiseOperations->addAction(addConstant);
    menuElementWiseOperations->addAction(negative);
    menuElementWiseOperations->addAction(mulConstant);
    menuElementWiseOperations->addAction(degree);
    menuElementWiseOperations->addAction(logarithm);
    menuElementWiseOperations->addAction(add);
    menuElementWiseOperations->addAction(mul);
    menuElementWiseOperations->addAction(linearContrast);
    connect(addConstant, SIGNAL(triggered(bool)), this, SLOT(addConstantSlot()));
    connect(negative, SIGNAL(triggered(bool)), this, SLOT(negativeSlot()));
    connect(mulConstant, SIGNAL(triggered(bool)), this, SLOT(mulConstantSlot()));
    connect(degree, SIGNAL(triggered(bool)), this, SLOT(degreeSlot()));
    connect(logarithm, SIGNAL(triggered(bool)), this, SLOT(logarithmSlot()));
    connect(add, SIGNAL(triggered(bool)), this, SLOT(addSlot()));
    connect(mul, SIGNAL(triggered(bool)), this, SLOT(mulSlot()));
    connect(linearContrast, SIGNAL(triggered(bool)), this, SLOT(linearContrastSlot()));

    QMenu* menuMorphological = new QMenu("Морфологическая обработка");
    QAction* erosion = new QAction("Эрозия");
    QAction* dilatation = new QAction("Дилатация");
    QAction* tripping = new QAction("Размыкание");
    QAction* locking = new QAction("Замыкание");
    menuMorphological->addAction(erosion);
    menuMorphological->addAction(dilatation);
    menuMorphological->addAction(tripping);
    menuMorphological->addAction(locking);
    connect(erosion, SIGNAL(triggered(bool)), this, SLOT(erosionSlot()));
    connect(dilatation, SIGNAL(triggered(bool)), this, SLOT(dilatationSlot()));
    connect(tripping, SIGNAL(triggered(bool)), this, SLOT(trippingSlot()));
    connect(locking, SIGNAL(triggered(bool)), this, SLOT(lockingSlot()));

    QMenu* menuStructuringElement = new QMenu("Структурирующий элемент");
    QAction* square = new QAction("квадрат 3x3");
    QAction* rectHorizontal = new QAction("Прямоугольник 1x3");
    QAction* rectVertical = new QAction("Прямоугольник 3x1");
    QAction* cross = new QAction("Крест 3x3");
    menuStructuringElement->addAction(square);
    menuStructuringElement->addAction(rectHorizontal);
    menuStructuringElement->addAction(rectVertical);
    menuStructuringElement->addAction(cross);
    connect(square, SIGNAL(triggered(bool)), this, SLOT(squareSlot()));
    connect(rectHorizontal, SIGNAL(triggered(bool)), this, SLOT(rectHorizontalSlot()));
    connect(rectVertical, SIGNAL(triggered(bool)), this, SLOT(rectVerticalSlot()));
    connect(cross, SIGNAL(triggered(bool)), this, SLOT(crossSlot()));


    menuBar()->addMenu(menuFile);
    menuBar()->addMenu(menuElementWiseOperations);
    menuBar()->addMenu(menuMorphological);
    menuBar()->addMenu(menuStructuringElement);

    QHBoxLayout* hLayout = new QHBoxLayout();
    originalImageLabel = new QLabel();
    originalImageLabel->setMinimumSize(550, 720);
    originalImageLabel->setMaximumSize(550, 720);
    QPixmap pixmap(imagePath);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    imagePixmap = &pixmap;
    originalImageLabel->setPixmap(*imagePixmap);
    processingImageLabel = new QLabel();
    processingImageLabel->setPixmap(*imagePixmap);
    hLayout->addWidget(originalImageLabel);
    hLayout->addWidget(processingImageLabel);
    hLayout->setAlignment(Qt::AlignCenter);
    imageMat = QImageToCvMat(pixmap.toImage());

    centralWidget()->setLayout(hLayout);
    setMinimumSize(1150, 750);
    setMaximumSize(1150, 750);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chooseFileSlot()
{
    QString imagePathTmp = QFileDialog::getOpenFileName(nullptr, "Open Image File", "", "Image Files (*.png *.jpg *.jpeg *.bmp *.BMP)");

    if (!imagePathTmp.isEmpty())
    {
        QPixmap pixmap(imagePathTmp);
        pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);

        if(!pixmap.isNull())
        {
            imagePixmap = &pixmap;
            imagePath = imagePathTmp;
            imageMat = cv::imread(imagePath.toStdString());
            originalImageLabel->setPixmap(*imagePixmap);
            processingImageLabel->setPixmap(*imagePixmap);
        }
    }
}

void MainWindow::addConstantSlot()
{
    bool ok;
    int constantToAdd = QInputDialog::getInt(nullptr, "Enter Integer", "Please enter an integer:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
    {
        cv::Mat processingMat(imageMat.clone());
        cv::add(imageMat.clone(), cv::Scalar(constantToAdd), processingMat);
        QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
        processingImageLabel->setPixmap(pixmap);
    }
}

void MainWindow::negativeSlot()
{
    cv::Mat negativeMat;
    cv::bitwise_not(imageMat.clone(), negativeMat);
    QImage qImage(negativeMat.data, negativeMat.cols, negativeMat.rows, negativeMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::mulConstantSlot()
{
    bool ok;
    double constantToMul = QInputDialog::getDouble(nullptr, "Enter Integer", "Please enter an double:", 0, -2147483647, 2147483647, 1, &ok);
    if(ok)
    {
        cv::Mat processingMat(imageMat.clone());
        cv::multiply(imageMat.clone(), cv::Scalar(constantToMul), processingMat);
        QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
        processingImageLabel->setPixmap(pixmap);
    }
}

void MainWindow::degreeSlot()
{
    bool ok;
    int degree = QInputDialog::getInt(nullptr, "Enter Integer", "Please enter an double:", 0, 2, 2147483647, 1, &ok);
    if(ok)
    {
        cv::Mat processingMat(imageMat.clone());
        cv::pow(imageMat.clone(), degree, processingMat);
        QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
        QPixmap pixmap = QPixmap::fromImage(qImage);
        pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
        processingImageLabel->setPixmap(pixmap);
    }
}

void MainWindow::logarithmSlot()
{
    cv::Mat logMat(imageMat.clone());
    logMat.convertTo(logMat, CV_32FC3);
    cv::add(logMat, cv::Scalar(1.0), logMat);
    cv::log(logMat, logMat);
    cv::normalize(logMat, logMat, 0, 255, cv::NORM_MINMAX);
    logMat.convertTo(logMat, CV_8U);
    QImage qImage(logMat.data, logMat.cols, logMat.rows, logMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::addSlot()
{
    cv::Mat processingMat;
    cv::add(imageMat.clone(), imageMat.clone(), processingMat);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::mulSlot()
{
    cv::Mat processingMat;
    cv::multiply(imageMat.clone(), imageMat.clone(), processingMat);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::linearContrastSlot()
{
    cv::Mat processingMat(imageMat.clone());

    double currentMin, currentMax;
    cv::minMaxLoc(processingMat, &currentMin, &currentMax);

    double alpha = 255.0 / (currentMax - currentMin);
    double beta = -currentMin * alpha;
    cv::convertScaleAbs(processingMat, processingMat, alpha, beta);

    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::erosionSlot()
{
    cv::Mat element = getStructuringEl();
    cv::Mat processingMat;
    cv::erode(imageMat.clone(), processingMat, element);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::dilatationSlot()
{
    cv::Mat element = getStructuringEl();
    cv::Mat processingMat;
    cv::dilate(imageMat.clone(), processingMat, element);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::trippingSlot()
{
    cv::Mat element = getStructuringEl();
    cv::Mat processingMat;
    cv::erode(imageMat.clone(), processingMat, element);
    cv::dilate(processingMat.clone(), processingMat, element);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::lockingSlot()
{
    cv::Mat element = getStructuringEl();
    cv::Mat processingMat;
    cv::dilate(imageMat.clone(), processingMat, element);
    cv::erode(processingMat.clone(), processingMat, element);
    QImage qImage(processingMat.data, processingMat.cols, processingMat.rows, processingMat.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(qImage);
    pixmap = pixmap.scaled(originalImageLabel->size(), Qt::KeepAspectRatio);
    processingImageLabel->setPixmap(pixmap);
}

void MainWindow::squareSlot()
{
    structuringElement = StructingElement::Square;
}

void MainWindow::rectHorizontalSlot()
{
    structuringElement = StructingElement::RectHorizontal;
}

void MainWindow::rectVerticalSlot()
{
    structuringElement = StructingElement::RectVertical;
}

void MainWindow::crossSlot()
{
    structuringElement = StructingElement::Cross;
}

cv::Mat MainWindow::QImageToCvMat(const QImage &image)
{
    cv::Mat mat(image.height(), image.width(), CV_8UC4, const_cast<uchar*>(image.bits()), image.bytesPerLine());
    cv::cvtColor(mat, mat, cv::COLOR_RGBA2BGR);
    return mat.clone();
}

cv::Mat MainWindow::getStructuringEl()
{
    if(structuringElement == StructingElement::Square)
    {
        return cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    }
    else if(structuringElement == StructingElement::RectHorizontal)
    {
        return cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, 3));
    }
    else if(structuringElement == StructingElement::RectVertical)
    {
        return cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 1));
    }
    else if(structuringElement == StructingElement::Cross)
    {
        return cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));
    }
}


