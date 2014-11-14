#ifndef PAINTOUTPUT_H
#define PAINTOUTPUT_H

#include <QtWidgets/QtWidgets>
#include "signalgenerator.h"

class PaintOutput : public QWidget
{
    Q_OBJECT
public:
    explicit PaintOutput(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const {
        return QSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    }
    virtual QSize sizeHint() const {return QSize(150,150);}

    void SetGenerator(SignalGenerator *iSignalGenerator){ExampleSignalGenerator = iSignalGenerator;}
signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent);

    SignalGenerator *ExampleSignalGenerator;
};

#endif // PAINTOUTPUT_H
