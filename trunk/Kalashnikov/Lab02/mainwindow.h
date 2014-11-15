#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include "paintoutput.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:

private:
    PaintOutput *ExampleGraphic;
};

#endif // MAINWINDOW_H
