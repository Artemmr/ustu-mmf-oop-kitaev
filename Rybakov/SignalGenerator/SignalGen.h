#ifndef SIGNALGEN_H
#define SIGNALGEN_H

class SignalGen
{
public:
    SignalGen();
    double GetSample(void) = 0;                 // метод получения последующего сэмпла от генератора
    void SetFrequency(double iFrequency) = 0;   // метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude) = 0;   // метод задания амплитуды генерируемого сигнала
    void SetOffset(double iOffset) = 0;         // метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition() = 0;                   // метод сброса текущего времени
    void SetDiscrFrequency(int iDescrFreq) = 0; // метод задания частоты дискретизации сигнала
};

#endif // SIGNALGEN_H
