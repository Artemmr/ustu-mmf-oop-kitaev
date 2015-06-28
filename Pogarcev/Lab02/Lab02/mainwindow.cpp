#include <QVBoxLayout>

#include "mainwindow.h"
#include "paintoutput.h"
#include "SGen.h"
#include "signalmixer.h"
#include "rclowpassfilter.h"

MainWindow::MainWindow(QWidget *iParent)
    : QWidget(iParent)
{
    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout (parent);
    vblayout->addWidget(PGraph = new PaintOutput(parent));

    SignalGenerator
        *PSGen1 = new SGen(),
        *PSGen2 = new SGen();
    SignalMixer *mixer;
    RCLowPassFilter *rclpfilter = new RCLowPassFilter();
    vblayout->addWidget(mixer = new SignalMixer(this));

    PSGen1->SetAmplitude(150.0);
    PSGen1->SetFrequency(5.0);

    PSGen2->SetAmplitude(50.0);
    PSGen2->SetFrequency(10.0);

    mixer->AddSource(PSGen1);
    mixer->AddSource(PSGen2);

    //rclpfilter->SetSource(mixer);

    PGraph->SetGenerator(mixer);

    connect(mixer, SIGNAL(UpdateOutput()), PGraph, SLOT(repaint()));
}

MainWindow::~MainWindow(){
}
