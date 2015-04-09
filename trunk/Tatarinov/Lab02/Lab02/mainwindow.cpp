#include <QVBoxLayout>
#include <QHBoxLayout>

#include "mainwindow.h"
#include "trianglewavegenerator.h"
#include "paintoutput.h"

MainWindow::MainWindow(QWidget *iParent)
    : QWidget(iParent)
{
    QWidget *parent = this;
    QVBoxLayout *vblyaout = new QVBoxLayout(parent);
    vblyaout->addWidget(ExGraphic = new PaintOutput(parent));

    SignalGenerator
            *ExTrapezioidWaveGenerator = new TriangleWaveGenerator();

    ExTrapezioidWaveGenerator->SetAmplitude(100.0);
    ExTrapezioidWaveGenerator->SetFrequency(5.0);

    ExGraphic->SetGenerator(ExTrapezioidWaveGenerator);
}

MainWindow::~MainWindow(){
}
