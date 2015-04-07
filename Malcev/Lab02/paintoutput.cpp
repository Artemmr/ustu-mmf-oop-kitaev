#include <QPainter>
#include "paintoutput.h"

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
    PSignalGen = 0;
}

void PaintOutput::paintEvent(QPaintEvent *iEvent){
    QPainter painter(this);
    const int x = height()/2;
    painter.setPen(Qt::black);
    painter.drawLine(0,x,width(),x);

    if (PSignalGen != 0){
        double values[2];
        values[0] = PSignalGen->GetSample();
        painter.setPen(Qt::red);
        for (int i = 0; i < width(); ++i){
            values[1] = PSignalGen->GetSample();
            painter.drawLine(i,x-values[0], i+1,x-values[1]);
            values[0] = values[1];
        }
    }
}

