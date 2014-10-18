#ifndef TESTPAINTER_H
#define TESTPAINTER_H

#include <QWidget>

class TestPainter : public QWidget
{
    Q_OBJECT
public:
    explicit TestPainter(QWidget *parent = 0);

    virtual QSizePolicy sizePolicy() const
        {return QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);}
    virtual QSize sizeHint() const {return QSize(150, 150);}
    
signals:
    
public slots:

protected:
    virtual void paintEvent(QPaintEvent *iEvent);
    
};

#endif // TESTPAINTER_H
