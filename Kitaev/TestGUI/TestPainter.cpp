#include "TestPainter.h"

#include <QPainter>

TestPainter::TestPainter(QWidget *parent) :
    QWidget(parent)
{
}

void TestPainter::paintEvent(QPaintEvent *iEvent)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawLine(0, 0, 100, 100);
}
