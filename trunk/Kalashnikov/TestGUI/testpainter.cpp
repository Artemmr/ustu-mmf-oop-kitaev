#include "testpainter.h"

#include <QPainter>

testpainter::testpainter(QWidget *parent) :
    QWidget(parent)
{
}

void testpainter::paintEvent(QPaintEvent *iEvent){ // отрисовка

    QPainter painter(this);

    painter.setPen(Qt::black);

    painter.drawLine(0, 0, 100, 100);
}
