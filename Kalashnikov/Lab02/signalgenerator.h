#ifndef SIGNALGENERATOR_H

#define SIGNALGENERATOR_H

class SignalGenerator
{
public:

    enum Result {
        Success,  /// всё ок
        BadValue /// не вписывается в ОДЗ
    }
    ;
    virtual double GetSample() = 0; //метод получения последующего сэмпла от генератора
    virtual Result SetFrequency(double iFrequency) = 0; // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude) = 0; // метод задания амплитуды генерируемого сигнала
    virtual Result SetOffset(double iOffset) = 0; // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition() = 0; // метод сброса текущего времени
    virtual Result SetDiscretizationFrequency(int iDescrFreq) = 0; // метод задания частоты дискретизации сигнала
};

#endif // SIGNALGENERATOR_H
