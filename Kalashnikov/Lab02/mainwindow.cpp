#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "mainwindow.h"
#include "trapezioidwavegenerator.h"
#include "paintoutput.h"
#include "signalmixer.h"
#include "rclowpassfilter.h"
#include "noisegenerator.h"

MainWindow::MainWindow(QWidget *iParent) :
    QWidget(iParent)
{

    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(parent);
    //QPushButton *bt0, *bt1;
    vblayout->addWidget(ExGraphic = new PaintOutput(parent));

    SignalGenerator
            *ExTrapezioidWaveGenerator  = new TrapezioidWaveGenerator(),
            *PNoiseGen = new NoiseGenerator();
    SignalMixer *mixer;
    RCLOWPASSFILTER *rclipfilter = new RCLOWPASSFILTER();

    vblayout->addWidget(mixer = new SignalMixer(this));

    ExTrapezioidWaveGenerator->SetAmplitude(100.0);
    ExTrapezioidWaveGenerator->SetFrequency(5.0);
    PNoiseGen->SetAmplitude(150);
    mixer->AddSignalSource(PNoiseGen);
    mixer->AddSignalSource(ExTrapezioidWaveGenerator);
    rclipfilter->SetSource(mixer);

    ExGraphic->SetGenerator(rclipfilter);

    connect(mixer, SIGNAL(UpdateOutput()), ExGraphic, SLOT(repaint()));
}

MainWindow::~MainWindow()
{

}
