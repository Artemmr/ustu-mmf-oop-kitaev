#include <QCoreApplication>
#include <iostream>
#include "signalgen.h"
#include "noisegen.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SignalGen *siggen = new NoiseGen();
    siggen->SetAmplitude(7.5);
    for ( int i = 0; i < 25; i++ )
    {
        cout<<siggen->GetSample()<<endl;
    }
    return a.exec();
}
