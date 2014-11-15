#include <QtWidgets/QHBoxLayout>

#include "mainwindow.h"
#include "signalgenerator.h"
#include "trapezioidwavegenerator.h"
#include "paintoutput.h"

MainWindow::MainWindow(QWidget *iparent) : QWidget(iparent) {

    QWidget *parent = this;
    QHBoxLayout *hblayout = new QHBoxLayout;
   
    hblayout->addWidget(ExampleGraphic = new PaintOutput(parent));

    SignalGenerator *ExampleTrapezioidWaveGenerator = new TrapezioidWaveGenerator();

    ExampleTrapezioidWaveGenerator->SetAmplitude(200);
    ExampleGraphic->SetGenerator(ExampleTrapezioidWaveGenerator);
}

MainWindow::~MainWindow()
{
}
