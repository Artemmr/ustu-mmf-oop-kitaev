#ifndef NOISEGEN_H
#define NOISEGEN_H
#include "signalgenerator.h"

class NoiseGenerator : public SignalGenerator
{
public:
    NoiseGenerator();
    double GetSample(void);                 // метод получения последующего сэмпла от генератора
    void SetFrequency(double iFrequency);   // метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude);   // метод задания амплитуды генерируемого сигнала
    void SetOffset(double iOffset);         // метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition();                   // метод сброса текущего времени
    void SetDiscretizationFrequency(int iDiscrFreq); // метод задания частоты дискретизации сигнала

protected:
    double
        Frequency,
        Amplitude,
        Offset;
    int
        DiscrFreq,
        Counter;
    unsigned int
        position;


};

#endif // NOISEGEN_H
