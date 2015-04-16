#ifndef SAMPLEGENERATOR_H
#define SAMPLEGENERATOR_H

#include "signalgenerator.h"

class SampleGenerator : public SignalGenerator
{
public:
    SampleGenerator();

    ///Абстрактные методы базового класса
    virtual double GetSample(); //метод получения последующего сэмпла от генератора
    virtual void SetFrequency(double iFrequency); // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude); // метод задания амплитуды генерируемого сигнала
    virtual void SetOffset(double iOffset); // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition(); // метод сброса текущего времени
    virtual void SetDiscretizationFrequency(int iDiscrFreq); // метод задания частоты дискретизации сигнала

    virtual QString GetName();

protected:
    double
        _amplitude,///амплитуда сигнала
        _frequency,///частота
        _phaseShift;///смещение фазы сигнала
    unsigned int
        _position;///Номер текущего сэмпла
    int
        _discrFreq;///Частота дискретизации сигнала

    int _number;///Порядковый номер объекта, по времени создания
};

#endif // SAMPLEGENERATOR_H
