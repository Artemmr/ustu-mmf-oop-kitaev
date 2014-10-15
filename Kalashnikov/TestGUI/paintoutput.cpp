#include "PaintOutput.h"

#include <QPainter>

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
}

void PaintOutput::paintEvent(QPaintEvent *iEvent)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawLine(0, 0, 100, 100);
}
