#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "PaintOutput.h"

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent)
{
    QWidget *parent = this;
    QHBoxLayout *hblayout = new QHBoxLayout(this);
    QPushButton *bt0, *bt1;
    QWidget *leftWidget = new QWidget(this);
    hblayout->addWidget(leftWidget);
    {
        QWidget *parent = leftWidget;
        QVBoxLayout *vlay = new QVBoxLayout(parent);
        vlay->addWidget(new QPushButton("Кнопка 2", parent));
        vlay->addWidget(new QPushButton("Кнопка 3", parent));
    }
    hblayout->addWidget(bt0 = new QPushButton("Кнопка 0", this));
    hblayout->addWidget(bt1 = new QPushButton("Кнопка 1", this));
    hblayout->addWidget(new PaintOutput(parent));

    connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click()));
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Кнопка 0 была нажата");
}

MainWindow::~MainWindow()
{
}
