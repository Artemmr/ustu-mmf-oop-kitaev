#include "TestClass.h"

TestClass::TestClass()
{
    _counter = 0;///счётчик семплов обнуляем
}

double TestClass::GetSample()
{
    _counter++;
    double k = 0.01;
    return cos(_counter*k);
    ///f = (Fdescr*k)/(2*П);
}
