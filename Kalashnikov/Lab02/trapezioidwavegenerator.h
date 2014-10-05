#ifndef TRAPEZIOIDWAVEGENERATOR_H

#define TRAPEZIOIDWAVEGENERATOR_H

#include <signalgenerator.h>

class TrapezioIDWaveGenerator : public SignalGenerator
{ // трапецеидальный сигнал
public:
    TrapezioIDWaveGenerator();
    //public signalgenerator
    double GetSample();  //метод получения последующего сэмпла от генератора
    void SetFrequency(double iFrequency); // метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude); // метод задания амплитуды генерируемого сигнала
    void SetOffset(double iOffset); // метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition(); // метод сброса текущего времени
    void SetDiscretizationFrequency(int iDescrFreq); // метод задания частоты дискретизации сигнала
    //public trapezioidwavegenerator
    void SetRizePeriod(double iRizePeriod); // Метод/функция нарастания/фронта сигнала
    void SetFallPeriod(double iFallPeriod); // Метод/функция уменьшения/спада сигнала.
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
