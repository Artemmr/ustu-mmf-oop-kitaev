#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "PaintOutput.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

signals:

public slots:

private:
    PaintOutput *ExGraphic;
};

#endif // MAINWINDOW_H
