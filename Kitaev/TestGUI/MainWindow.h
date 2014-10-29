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

public slots:
    void button0Click();

private:
    PaintOutput *_funcPainter;

};

#endif // MAINWINDOW_H
