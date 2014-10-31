#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "PaintOutput.h"

//#include "TestPainter.h"

#include "SampleGenerator.h"

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent)
{
    QWidget *parent = this;
    QHBoxLayout *hblayout = new QHBoxLayout(parent);
    QPushButton *bt0, *bt1;
    QWidget *leftWidget = new QWidget(parent);
    hblayout->addWidget(leftWidget);
    {
        QWidget *parent = leftWidget;
        QVBoxLayout *vlay = new QVBoxLayout(parent);
        vlay->addWidget(new QPushButton("Button 2", parent));
        vlay->addWidget(new QPushButton("Button 3", parent));
    }
    hblayout->addWidget(bt0 = new QPushButton("Button 0", parent));
    hblayout->addWidget(bt1 = new QPushButton("Button 1", parent));
    hblayout->addWidget(_funcPainter = new PaintOutput(parent));

    SignalGenerator *_siggen = new SampleGenerator();

    _siggen->SetAmplitude(30);
    _funcPainter->SetGenerator(_siggen);

    connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click()));
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button0 was clicked");
}

MainWindow::~MainWindow()
{
}
