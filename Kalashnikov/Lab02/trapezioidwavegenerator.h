#ifndef TRAPEZIOIDWAVEGENERATOR_H

#define TRAPEZIOIDWAVEGENERATOR_H

#include <signalgenerator.h>

class TrapezioidWaveGenerator : public SignalGenerator
{ // трапецеидальный сигнал
public:
    TrapezioidWaveGenerator();
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

protected:
    unsigned int
        _position; /// номер сэмпла
    double
        _amplitude, /// Амлитуда сигнала
        _frequency, /// частота сигнала
        _phaseShift, /// смещение фазы сигнала
        _RizePeriod, /// коэфициент нагнетания волны 
        _FallPeriod;  /// коэфициент спада волны
    int
        _DescrFreq; /// частота дискретизации сигнала
    
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
