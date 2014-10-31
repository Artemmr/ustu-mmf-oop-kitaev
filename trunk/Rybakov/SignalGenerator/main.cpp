#include <QApplication>
//#include <iostream>
//#include "signalgen.h"
//#include "noisegen.h"
#include "mainwindow.h"
//using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow GraphWindow;
    GraphWindow.show();
    /*SignalGen *siggen = new NoiseGen();
    siggen->SetAmplitude(7.5);
    for ( int i = 0; i < 25; i++ )
    {
        cout<<siggen->GetSample()<<endl;
    }/*/
    return a.exec();
}
