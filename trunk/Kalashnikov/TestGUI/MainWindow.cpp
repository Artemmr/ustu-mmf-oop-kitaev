#include <MainWindow.h>
#include <QHBoxLayout> // диспетчер горизонталь
#include <QVBoxLayout> // диспетчер вертикаль
#include <QPushButton>

#include <testpainter.h>
#include <paintoutput.h>

MainWindow::MainWindow(QWidget *iParent):
    QWidget(iParent), _a(10)
{
    QWidget *parent = this;

    QHBoxLayout *hblayout = new QHBoxLayout(parent); // this - тип main windows *
    QPushButton *bt0, *bt1;

    QWidget *leftWidget = new QWidget(parent);

    hblayout->addWidget(leftWidget);
    {
        QWidget *parent = leftWidget;
        QVBoxLayout *vlay = new QVBoxLayout (parent);
        vlay->addWidget(new QPushButton("Button 2", parent));
        vlay->addWidget(new QPushButton("Button 3", parent));
    }
    //Добавим в диспетчер размещений родителем будет окошечко.
    // кнопки

    testpainter *_painter = new testpainter(parent);
    hblayout->addWidget(_painter);
    hblayout->

    hblayout->addWidget(bt0 = new QPushButton("Кнопка 0", this));
    hblayout->addWidget(bt1 = new QPushButton("Кнопка 1", this));
    hblayout->addWidget(new PaintOutput(parent));

    connect(bt0, SIGNAL(clicked()), this, SLOT(button0Click())); //отправитель, какой сигнал, куда
}

void MainWindow::button0Click()
{
    this->setWindowTitle("Button 0 was click");
   // this->width(600);
   // this->height()
}

MainWindow::~MainWindow()
{
}
