#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include "QString"

class SignalGenerator
{
public:

    enum Result {
        Success,  /// всё ок
        BadValue  /// не вписывается в ОДЗ
    };

    virtual double GetSample() = 0;                                 /// получения последующего сэмпла от генератора
    virtual void ResetPosition() = 0;                               /// сброс текущего времени
    virtual void SetAmplitude(double iAmplitude) = 0;               /// задание амплитуды генерируемого сигнала
    virtual Result SetFrequency(double iFrequency) = 0;             /// задание частоты генерируемого сигнала
    virtual Result SetOffset(double iOffset) = 0;                   /// задание сдвига фазы относительно начала отсчёта по времени
    virtual Result SetDiscretizationFrequency(int iDescrFreq) = 0;  /// задание частоты дискретизации сигнала

    virtual QString GetName();
};

#endif // SIGNALGENERATOR_H
