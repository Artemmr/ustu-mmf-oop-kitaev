#include <QVBoxLayout>

#include "mainwindow.h"
#include "paintoutput.h"
#include "SGen.h"

MainWindow::MainWindow(QWidget *iParent)
    : QWidget(iParent)
{
    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout (parent);
    vblayout->addWidget(PGraph = new PaintOutput(parent));

    SignalGenerator
        *PSGen1 = new SGen();

    PSGen1->SetAmplitude(150.0);
    PSGen1->SetFrequency(5.0);

    PGraph->SetGenerator(PSGen1);
}

MainWindow::~MainWindow(){
}
