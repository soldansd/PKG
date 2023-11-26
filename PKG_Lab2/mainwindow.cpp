#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addBtn = new QPushButton("Add");
    addFolderBtn = new QPushButton("Add folder");
    clearBtn = new QPushButton("Clear");
    ui->table->setColumnCount(5);
    ui->table->setHorizontalHeaderLabels({"Name", "Size", "Resolution", "Colour depth", "Compression"});
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    QGridLayout *grid = new QGridLayout(this->centralWidget());
    grid->addWidget(addBtn, 0, 0, 1, 2);
     grid->addWidget(addFolderBtn, 0, 2, 1, 2);
    grid->addWidget(clearBtn, 0, 4, 1, 2);
    grid->addWidget(ui->table, 1, 0, 4, 6);
    setWindowTitle("Images info");

    compressions["bmp"] = "No compression";
    compressions["BMP"] = "No compression";
    compressions["gif"] = "LZW compression";
    compressions["png"] = "Deflate compression";
    compressions["jpg"] = "JPEG compression";
    compressions["jpeg"] = "JPEG compression";
    compressions["tiff"] = "JPEG, ZIP,LZW compression";
    compressions["pcx"] = "RLE compression";

    dirFilter << "*.jpg" << "*.jpeg" << "*.BMP" << "*.gif" << "*.tif" << "*.bmp" << "*.png" << "*.pcx";

    connect(addBtn, SIGNAL(clicked()), this, SLOT(addBtnClicked()));
    connect(addFolderBtn, SIGNAL(clicked()), this, SLOT(addFolderBtnClicked()));
    connect(clearBtn, SIGNAL(clicked()), this, SLOT(clearBtnClicked()));
    connect(ui->table, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemDoubleClicked(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addBtnClicked()
{
    QStringList selectedFiles = QFileDialog::getOpenFileNames(this, "Choose images", "", "Images (*.jpg *.jpeg *.gif *.tif *.bmp *.BMP *.png *.pcx)");
    if (!selectedFiles.isEmpty())
    {
        addItemsToTable(selectedFiles);
    }
}

void MainWindow::addFolderBtnClicked()
{
    QString newDirPath = QFileDialog::getExistingDirectory(this, "Choose folder");
    if (!newDirPath.isEmpty())
    {
        QDir newDir(newDirPath);
        newDir.setNameFilters(dirFilter);
        QFileInfoList fileList(newDir.entryInfoList(QDir::Filter::Files));
        QStringList filepaths;
        for (const auto& x : fileList)
            filepaths.append(x.absoluteFilePath());
        addItemsToTable(filepaths);
    }
}

void MainWindow::clearBtnClicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->table->selectedItems();
    if (selectedItems.size() == 0 && ui->table->rowCount() != 0)
    {
        ui->table->clearContents();
        ui->table->setRowCount(0);
    }
    else
    {
        int columns = ui->table->columnCount();
        for (int i = 0; i < selectedItems.size() / columns; i++)
        {
            int row = selectedItems[i * columns]->row();
            ui->table->removeRow(row);
        }
    }
}

void MainWindow::tableItemDoubleClicked(int row, int column)
{
    for (int i = 0; i < ui->table->columnCount(); i++)
        ui->table->item(row, i)->setSelected(false);

    QDialog *dialog = new QDialog(this);
    QHBoxLayout diagLayout(dialog);
    QPixmap pixmap(dynamic_cast<NameTableWidgetItem*>(ui->table->item(row, 0))->filePath);
    QLabel label;
    label.setPixmap(pixmap);

    dialog->setMaximumHeight(pixmap.height() + 15);
    dialog->setMinimumHeight(pixmap.height() + 15);
    dialog->setMaximumWidth(pixmap.width() + 15);
    dialog->setMinimumWidth(pixmap.width() + 15);

    diagLayout.addWidget(&label);
    dialog->exec();
}

void MainWindow::addItemsToTable(const QStringList &selectedFiles)
{
    for (int i = 0; i < selectedFiles.size(); ++i)
    {
        QFileInfo fileInfo(selectedFiles[i]);
        QImage image(selectedFiles[i]);
        if (!image.isNull())
        {
            NameTableWidgetItem* name = new NameTableWidgetItem(fileInfo.fileName(), selectedFiles[i]);
            SizeTableWidgetItem* size =
                new SizeTableWidgetItem(QString::number(image.size().width()) + " x " + QString::number(image.size().height()),
                                        image.size().width(), image.size().height());

            QTableWidgetItem* resolution = new QTableWidgetItem(QString::number(static_cast<int>(min(image.dotsPerMeterX() , image.dotsPerMeterY()) / 39.37)));
            QTableWidgetItem* depth = new QTableWidgetItem(QString::number(image.depth()));
            QTableWidgetItem* comp = new QTableWidgetItem(compressions[fileInfo.suffix()]);

            name->setFlags(name->flags() & ~Qt::ItemIsEditable);
            size->setFlags(size->flags() & ~Qt::ItemIsEditable);
            resolution->setFlags(resolution->flags() & ~Qt::ItemIsEditable);
            depth->setFlags(depth->flags() & ~Qt::ItemIsEditable);
            comp->setFlags(comp->flags() & ~Qt::ItemIsEditable);

            ui->table->insertRow(ui->table->rowCount());
            ui->table->setItem(ui->table->rowCount() - 1, 0, name);
            ui->table->setItem(ui->table->rowCount() - 1, 1, size);
            ui->table->setItem(ui->table->rowCount() - 1, 2, resolution);
            ui->table->setItem(ui->table->rowCount() - 1, 3, depth);
            ui->table->setItem(ui->table->rowCount() - 1, 4, comp);
        }
    }
}



