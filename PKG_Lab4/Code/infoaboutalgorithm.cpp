#include "infoaboutalgorithm.h"
#include <QScrollBar>

InfoAboutAlgorithm::InfoAboutAlgorithm(QWidget *parent) : QPlainTextEdit(parent)
{
    setReadOnly(true);
    setFrameStyle(QFrame::StyledPanel);
}

void InfoAboutAlgorithm::writeLine(const QString& message, int tabCount)
{
    QString tabStr = "";
    for (int i = 0; i < tabCount; ++i)
    {
        tabStr += "      ";
    }
    appendPlainText(tabStr + message);
}
void InfoAboutAlgorithm::writeSeparator()
{
    writeLine("\n########################################\n");
}
