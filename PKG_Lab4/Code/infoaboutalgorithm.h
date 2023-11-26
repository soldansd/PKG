#ifndef INFOABOUTALGORITHM_H
#define INFOABOUTALGORITHM_H

#include <QWidget>
#include <QPlainTextEdit>

class InfoAboutAlgorithm : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit InfoAboutAlgorithm(QWidget *parent = nullptr);

    void writeSeparator();
    void writeLine(const QString& message, int tabCount = 0);
};

#endif // INFOABOUTALGORITHM_H
