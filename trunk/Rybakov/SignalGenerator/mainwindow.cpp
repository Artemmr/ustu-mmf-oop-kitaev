#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "mainwindow.h"
#include "risovalka.h"
#include "noisegenerator.h"
#include "signalmixer.h"
#include "rclowpassfilter.h"

MainWindow::MainWindow(QWidget *iparent) :
    QWidget(iparent)
{
    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(parent);
    //QPushButton *BNewGraph;
    //vblayout->addWidget(BNewGraph = new QPushButton("New graph",parent));
    vblayout->addWidget(PGraph = new Risovalka(parent));

    SignalGenerator
        *PNoiseGen_1 = new NoiseGenerator(),
        *PNoiseGen_2 = new NoiseGenerator();
    SignalMixer *mixer;
    RCLowPassFilter *rclpfilter = new RCLowPassFilter();
    vblayout->addWidget(mixer = new SignalMixer(this));

    PNoiseGen_1->SetAmplitude(150);
    PNoiseGen_2->SetAmplitude(100);

    mixer->AddSource(PNoiseGen_1);
    mixer->AddSource(PNoiseGen_2);
    rclpfilter->SetSource(mixer);

    PGraph->SetGenerator(rclpfilter);

    connect(mixer, SIGNAL(UpdateOutput()), PGraph, SLOT(repaint()));
    //connect(BNewGraph, SIGNAL(clicked()), this, SLOT(PaintGraph()));
}

MainWindow::~MainWindow()
{
}
