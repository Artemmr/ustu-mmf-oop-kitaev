#include <QCoreApplication>

#include <QString>

int b;


void VoidFunction()
{
    int a;
    int b;
}

int inFunction(int iArg1)
{
    return iArg1/2;
}

double inFunction(double iArg1)
{
    return iArg1/2.;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bool bool1;
    bool1 = true;
    bool1 = false;

    char ch = 'a';

    int i16 = -25;

    int result = inFunction(i16);

    double dresult = inFunction((double)i16);

    int *pi16, **ppi16;

    pi16 = &i16;

    ppi16 = &pi16;

    *pi16 = -30;

    QString string1;
    string1 = "Это строка 1";

    return a.exec();
}
