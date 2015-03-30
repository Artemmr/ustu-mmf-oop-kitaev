#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "mainwindow.h"
#include "trapezioidwavegenerator.h"
#include "paintoutput.h"
#include "signalmixer.h"

MainWindow::MainWindow(QWidget *iParent) :
    QWidget(iParent)
{

    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(parent);
    //QPushButton *bt0, *bt1;
    vblayout->addWidget(ExGraphic = new PaintOutput(parent));

    SignalGenerator
            *ExTrapezioidWaveGenerator  = new TrapezioidWaveGenerator(),
            *ExTrapezioidWaveGenerator2 = new TrapezioidWaveGenerator();

    SignalMixer
            *mixer;

    vblayout->addWidget(mixer = new SignalMixer(this));

    ExTrapezioidWaveGenerator->SetAmplitude(100.0);
    ExTrapezioidWaveGenerator->SetFrequency(5.0);
    ExTrapezioidWaveGenerator2->SetFrequency(3.0);
    ExTrapezioidWaveGenerator2->SetAmplitude(10.0);


    mixer->AddSignalSource(ExTrapezioidWaveGenerator);
    mixer->AddSignalSource(ExTrapezioidWaveGenerator2);

    ExGraphic->SetGenerator(mixer);
}

MainWindow::~MainWindow()
{

}
