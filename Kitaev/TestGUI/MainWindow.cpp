#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "PaintOutput.h"

//#include "TestPainter.h"

#include "SampleGenerator.h"
#include "signalmixer.h"
#include "rclowpassfilter.h"
#include "noisegen.h"

#include <math.h>

#include "Common.h"

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
            *siggen2 = new SampleGenerator(),
            *_siggen = new SampleGenerator();
    NoiseGenerator *_ng0 = new NoiseGenerator();
    SignalMixer *mixer;
    RCLowPassFilter
            *rclpfilter0 = new RCLowPassFilter(),
            *rclpfilter1 = new RCLowPassFilter(),
            *rclpfilter2 = new RCLowPassFilter();
    vblayout->addWidget(mixer = new SignalMixer(this));

    _siggen->SetAmplitude(150);
    _siggen->SetFrequency(5);
    siggen2->SetAmplitude(15);
    siggen2->SetFrequency(150);

    _ng0->SetAmplitude(150);

    double rc = 1.0/(2.0*M_PI*100);
    rclpfilter0->SetRC(rc);
    rclpfilter1->SetRC(rc);
    rclpfilter2->SetRC(rc);

    ///Подключаем источники сигналов к микшеру
    mixer->AddSignalSource(_siggen);
    mixer->AddSignalSource(siggen2);
    mixer->AddSignalSource(_ng0);

    rclpfilter0->SetSource(mixer);
    rclpfilter1->SetSource(rclpfilter0);
    rclpfilter2->SetSource(rclpfilter1);

    _funcPainter->SetGenerator(rclpfilter2);
    //_funcPainter->SetGenerator(mixer);

    connect(mixer, SIGNAL(UpdateOutput()), _funcPainter, SLOT(repaint()));

    //connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click()));
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button0 was clicked");
}

MainWindow::~MainWindow()
{
}

