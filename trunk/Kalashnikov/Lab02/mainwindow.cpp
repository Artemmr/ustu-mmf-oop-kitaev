#include <QVBoxLayout>

#include "mainwindow.h"
#include "signalgenerator.h"
#include "trapezioidwavegenerator.h"
#include "paintoutput.h"

MainWindow::MainWindow(QWidget *iparent) : QWidget(iparent) {

    QWidget *Parent = this;
    QVBoxLayout *vblayout = new QVBoxLayout(Parent);
   
    vblayout->addWidget(ExGraphic = new PaintOutput(Parent));

    SignalGenerator *ExTrapezioidWaveGenerator = new TrapezioidWaveGenerator();

    ///ExTrapezioidWaveGenerator->SetAmplitude(100);
    ///ExTrapezioidWaveGenerator->SetDiscretizationFrequency(5);
    ExGraphic->SetGenerator(ExTrapezioidWaveGenerator);
}

MainWindow::~MainWindow()
{
}
