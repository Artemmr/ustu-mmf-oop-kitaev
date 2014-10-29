#ifndef SIGNALGEN_H
#define SIGNALGEN_H

class SignalGen
{
public:
    virtual double GetSample(void);                 // метод получения последующего сэмпла от генератора
    virtual void SetFrequency(double iFrequency);   // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude);   // метод задания амплитуды генерируемого сигнала
    virtual void SetOffset(double iOffset);         // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                   // метод сброса текущего времени
    virtual void SetDiscrFrequency(int iDescrFreq); // метод задания частоты дискретизации сигнала
};

#endif // SIGNALGEN_H
