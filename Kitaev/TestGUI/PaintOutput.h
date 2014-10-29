#ifndef PAINTOUTPUT_H
#define PAINTOUTPUT_H

#include <QWidget>

#include "signalgenerator.h"

class PaintOutput : public QWidget
{
    Q_OBJECT
public:
    explicit PaintOutput(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const
        {return QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);}
    virtual QSize sizeHint() const {return QSize(150, 150);}

    ///Метод задания текущего генератора сигналов
    void SetGenerator(SignalGenerator *iSignalGenerator){_sigGen = iSignalGenerator;}
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent);

    SignalGenerator *_sigGen;///указатель на экземпляр генератора сигналов

};

#endif // PAINTOUTPUT_H
