#ifndef TESTPAINTER_H
#define TESTPAINTER_H

#include <QWidget>

class testpainter : public QWidget
{
    Q_OBJECT
public:
    explicit testpainter(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const{
        return QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum)
    }



signals:

public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent); // отрисовка

};

#endif // TESTPAINTER_H
