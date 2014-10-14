#include "testclass.h"

TestClass::TestClass()
{// Метод вызываемый при создании класса
    _counter = 0; // счётчик сэмплов обонуляется

}

double TestClass::GetSample(){
    _counter++;
    return cos(_counter*0.01); //1000/1
    // f = (Fdescr*0.01)/(2*pi)
}
