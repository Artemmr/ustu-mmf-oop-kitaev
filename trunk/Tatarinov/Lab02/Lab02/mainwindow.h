#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class PaintOutput;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *iParent = 0);
    ~MainWindow();

private:
    PaintOutput *ExGraphic;
};

#endif // MAINWINDOW_H
