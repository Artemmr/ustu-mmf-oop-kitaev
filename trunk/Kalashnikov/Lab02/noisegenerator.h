#ifndef NOISEGEN_H
#define NOISEGEN_H
#include "signalgenerator.h"

class NoiseGenerator : public SignalGenerator
{
public:

    NoiseGenerator();
    virtual double GetSample(void);                 // метод получения последующего сэмпла от генератора
    virtual Result SetFrequency(double iFrequency);   // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude);   // метод задания амплитуды генерируемого сигнала
    virtual Result SetOffset(double iOffset);         // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                   // метод сброса текущего времени
    virtual Result SetDiscretizationFrequency(int iDescrFreq); // метод задания частоты дискретизации сигнала

    virtual QString GetName();

protected:
    double
        Frequency,
        Amplitude,
        Offset;
    int
        DiscrFreq,
        number;

    unsigned int
        position;

};

#endif // NOISEGEN_H
