#ifndef PAINTOUTPUT_H
#define PAINTOUTPUT_H

#include <QWidget>

class PaintOutput : public QWidget
{
    Q_OBJECT
public:
    explicit PaintOutput(QWidget *parent = 0);

signals:

public slots:

protected:
    virtual void paintEvent (QPaintEvent *iEvent);

};

#endif // PAINTOUTPUT_H
