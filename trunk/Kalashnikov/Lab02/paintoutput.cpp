#include "paintoutput.h"
#include <QPainter>

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
    ExampleSignalGenerator = 0;
}

void PaintOutput::paintEvent(QPaintEvent *iEvent){
    QPainter painter(this);
    int x = height()/2;
    painter.setPen(Qt::red);
    painter.drawLine(0,x,width(),x);
    /*
    if (ExampleSignalGenerator!=0){
        double values[2];
        values[0] = ExampleSignalGenerator->GetSample();

        for (int i = 0; i<width(); ++i){
            values[1] = ExampleSignalGenerator->GetSample();
            painter.drawLine(i,x-values[0], i+1, x-values[1]);
            values[0] = values[1];
        }
    }
    */
}
