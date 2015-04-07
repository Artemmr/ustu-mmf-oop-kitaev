#include <QHBoxLayout>
#include <QVBoxLayout>

#include "mainwindow.h"
#include "paintoutput.h"
#include "ngen.h"


MainWindow::MainWindow(QWidget *iParent) :
    QWidget(iParent)
{
    QWidget *parent = this;
    QVBoxLayout *vblyaout = new QVBoxLayout (parent);
    vblyaout->addWidget(PGraph = new PaintOutput(parent));

    SignalGenerator
            *PNGen_1 = new NGen();

    PNGen_1->SetAmplitude(150.0);
    PNGen_1->SetFrequency(5.0);

    PGraph->SetGenerator(PNGen_1);

}

MainWindow::~MainWindow(){
}
