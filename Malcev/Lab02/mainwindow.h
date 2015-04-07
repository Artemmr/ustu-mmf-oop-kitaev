#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class PaintOutput;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    PaintOutput *PGraph;
};

#endif // MAINWINDOW_H
