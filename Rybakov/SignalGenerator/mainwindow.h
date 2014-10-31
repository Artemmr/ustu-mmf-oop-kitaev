#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class Risovalka;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:

private:
    Risovalka *PGraph;

};

#endif // MAINWINDOW_H
