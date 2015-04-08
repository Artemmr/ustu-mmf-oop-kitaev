#include "paintoutput.h"
#include <QPainter>

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
    _sinGen = 0;
}

void PaintOutput::paintEvent(QPaintEvent *iEvent){
    QPainter painter(this);
    int x = height()/2;
    painter.setPen(Qt::black);
    painter.drawLine(0,x,width(),x);

    if (_sinGen!=0){
        double values[2];
        values[0] = _sinGen->GetSample();
        painter.setPen(Qt::red);
        for (int i = 0; i < width(); ++i){
            values[1] = _sinGen->GetSample();
            painter.drawLine(i,x-values[0],i+1,x-values[1]);
            values[0] = values [1];
        }
    }
}
