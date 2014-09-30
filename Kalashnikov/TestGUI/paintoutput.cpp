#include "paintoutput.h"
#include <QPainter>

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
    QPainter painter (this);
    painter.setPen(_funcColor);
    painter.drawLine(0, 0, 100, 100);
}
