#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>

#include "mainwindow.h"
#include "signalgenerator.h"
#include "trapezioidwavegenerator.h"
#include "paintoutput.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    QWidget *iparent = this;
    QHBoxLayout *hblayout = new QHBoxLayout;
   
    hblayout->addWidget(ExampleGraphic = new PaintOutput(parent));

    SignalGenerator *ExampleTrapezioidWaveGenerator = new TrapezioidWaveGenerator();

    ExampleTrapezioidWaveGenerator->SetAmplitud
}
