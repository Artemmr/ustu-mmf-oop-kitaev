#ifndef PAINTOUTPUT_H
#define PAINTOUTPUT_H

#include <QWidget>

#include "signalgenerator.h"

class PaintOutput : public QWidget
{
    Q_OBJECT
public:
    explicit PaintOutput(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const {return QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);}
    virtual QSize sizeHint() const {return QSize(700,450);}
    void SetGenerator(SignalGenerator *iSignalGenerator){_sinGen = iSignalGenerator;}
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent);
    SignalGenerator *_sinGen;
};

#endif // PAINTOUTPUT_H
