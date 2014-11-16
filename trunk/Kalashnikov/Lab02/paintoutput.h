#ifndef PAINTOUTPUT_H
#define PAINTOUTPUT_H

#include <QWidget>
#include "signalgenerator.h"

class PaintOutput : public QWidget
{
    Q_OBJECT
public:
    explicit PaintOutput(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const {
        return QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    }
    virtual QSize sizeHint() const {return QSize(800,600);}

    void SetGenerator(SignalGenerator *iSignalGenerator){ExSignalGenerator = iSignalGenerator;}
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent); ///Рисовалка

    SignalGenerator *ExSignalGenerator; /// указатель на экземпляр генератора сигналов
};

#endif // PAINTOUTPUT_H
