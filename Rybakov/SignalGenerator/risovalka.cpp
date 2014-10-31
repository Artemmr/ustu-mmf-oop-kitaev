#include <QPainter>
#include "risovalka.h"

Risovalka::Risovalka(QWidget *parent) :
    QWidget(parent)
{
    PSignalGen = 0;//обнуляем указатель, чтобы понимать, что генератора ещё нет
}

void Risovalka::paintEvent(QPaintEvent *iEvent)
{
    QPainter painter(this);
    const int abscissa = height()/2;
    painter.setPen(Qt::black);
    painter.drawLine(0, abscissa, width(), abscissa);

    if(PSignalGen!=0)
    {
        double values[2];
        values[0] = PSignalGen->GetSample();
        for(int i=0; i<width(); ++i)
        {
            values[1] = PSignalGen->GetSample();
            painter.drawLine(i, abscissa-values[0], i+1,abscissa-values[1]);
            values[0] = values[1];
        }
    }
}
