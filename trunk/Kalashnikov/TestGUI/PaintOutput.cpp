#include "PaintOutput.h"

#include <QPainter>

PaintOutput::PaintOutput(QWidget *parent) :
    QWidget(parent)
{
    _sigGen = 0;///обнуляем указатель, чтобы понимать, что генератора ещё нет
}

void PaintOutput::paintEvent(QPaintEvent *iEvent)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawLine(0, 0, 100, 100);

    ///Перед попыткой отрисовать функцию с генератора, проверим есть ли генератор
    if(_sigGen!=0)
    {
        ///Всё в порядке, генератор вроде существует, от "мусорного" указателя так не застраховаться
        double values[2];///массив двух значений, по которым будет строится отрезок
        values[0] = _sigGen->GetSample();
        const int heightby2 = height()/2;
        for(int i = 1; i<width(); ++i)
        {
            values[1] = _sigGen->GetSample();
            painter.drawLine(i-1, heightby2-values[0], i, heightby2-values[1]);
            values[0] = values[1];
        }
    }

}
