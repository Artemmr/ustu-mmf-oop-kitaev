#ifndef TESTCLASS_H
#define TESTCLASS_H

///Тестовый класс, реализующий пример генератора
///частота дискретизации 1000 Гц
class TestClass
{
public:
    TestClass();

    double GetSample();

private:
    ///Счётчик семплов
    int _counter;
};

#endif // TESTCLASS_H
