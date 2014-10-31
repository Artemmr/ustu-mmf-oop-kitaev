#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "mainwindow.h"
#include "risovalka.h"
#include "noisegen.h"

MainWindow::MainWindow(QWidget *iparent) :
    QWidget(iparent)
{
    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(parent);
    QPushButton *BNewGraph;
    vblayout->addWidget(BNewGraph = new QPushButton("New graph",parent));
    vblayout->addWidget(PGraph = new Risovalka(parent));

    SignalGen *PNoiseGen = new NoiseGen();

    PNoiseGen->SetAmplitude(200);
    PGraph->SetGenerator(PNoiseGen);

    //connect(BNewGraph, SIGNAL(clicked()), this, SLOT(PaintGraph()));
}

MainWindow::~MainWindow()
{
}
