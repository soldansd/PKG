#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <map>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBtnClicked();
    void addFolderBtnClicked();
    void clearBtnClicked();
    void tableItemDoubleClicked(int row, int column);
    void addItemsToTable(const QStringList& selectedFiles);

private:
    Ui::MainWindow *ui;
    QPushButton* addBtn;
    QPushButton* addFolderBtn;
    QPushButton* clearBtn;
    map<QString, QString> compressions;
    QStringList dirFilter;
};


class NameTableWidgetItem : public QTableWidgetItem
{
public:
    QString filePath;
    NameTableWidgetItem(const QString& fileName, const QString& filePath) : QTableWidgetItem(fileName)
    {
        this->filePath = filePath;
    }
};

class SizeTableWidgetItem : public QTableWidgetItem
{
public:
    int width;
    int height;

    SizeTableWidgetItem(const QString& fileName, int width, int height) : QTableWidgetItem(fileName)
    {
        this->width = width;
        this->height = height;
    }

    bool operator<(const QTableWidgetItem& other) const
    {
        const SizeTableWidgetItem* aOther = dynamic_cast<const SizeTableWidgetItem*>(&other);
        return width * height < aOther->width * aOther->height;
    }
};

#endif // MAINWINDOW_H
