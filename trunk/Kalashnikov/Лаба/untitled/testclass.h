#ifndef TESTCLASS_H
#define TESTCLASS_H
//Пример генератора
//Частота дискретизации 1 кГц
class TestClass
{
public:// доступные всем члены класса
    TestClass();

    double GetSample();

private: // лишь внутри

   int _counter;// счётчик сэмплов

protected: // внутри и видно наследника
};

#endif // TESTCLASS_H
