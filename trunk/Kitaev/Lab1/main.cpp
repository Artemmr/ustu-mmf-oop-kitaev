#include <QtCore/QCoreApplication>

#include <QString>

int b;

void VoidFunction()
{
    int a;
    int b;
}

int intFunction(int iArg1)
{
    return iArg1/2;
}

double intFunction(double iArg1)
{
    return iArg1/2.0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    int b = 0;

    bool bool1;
    bool1 = true;
    bool1 = false;

    char ch = 'a';

    uint8_t ui8 = 12;

    int i16 = -25;

    int result = intFunction(i16);

    double dresult = intFunction((double)i16);

    int *pi16, **ppi16;

    pi16 = &i16;

    ppi16 = &pi16;

    *pi16 = -30;

    QString string1;
    string1 = "Это строка 1";

    return a.exec();
}
