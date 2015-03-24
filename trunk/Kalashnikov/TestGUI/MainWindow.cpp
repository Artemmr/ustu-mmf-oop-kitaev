#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "PaintOutput.h"

//#include "TestPainter.h"

#include "SampleGenerator.h"
#include "signalmixer.h"

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent)
{
    QWidget *parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(parent);
    QPushButton *bt0, *bt1;

    //hblayout->addWidget(bt0 = new QPushButton("Button 0", parent));
    //hblayout->addWidget(bt1 = new QPushButton("Button 1", parent));
    vblayout->addWidget(_funcPainter = new PaintOutput(parent));

    SignalGenerator
            *_siggen = new SampleGenerator(),
            *siggen2 = new SampleGenerator();
    SignalMixer *mixer;
    vblayout->addWidget(mixer = new SignalMixer(this));

    _siggen->SetAmplitude(150);
    _siggen->SetFrequency(5);
    siggen2->SetAmplitude(15);
    siggen2->SetFrequency(23);

    mixer->AddSignalSource(_siggen);
    mixer->AddSignalSource(siggen2);

    _funcPainter->SetGenerator(mixer);

    //connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click()));
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button0 was clicked");
}

MainWindow::~MainWindow()
{
}
