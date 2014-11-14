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
    void SetRizeTime(double iRizeTime); // Время нарастания
    void SetFallTime(double iFallTime); // Время спада
    void SetPeakTime(double iPeakTime); // Время на пике
    //exp

protected:
    unsigned int
        _Position; /// номер сэмпла
    double
        _Amplitude, /// Амлитуда сигнала
        _Frequency, /// частота сигнала
        _PhaseShift, /// смещение фазы сигнала
        _RizeTime, /// коэфициент нагнетания волны
        _PeakTime, /// Скважность, время пика сколько идёт
        _FallTime,  /// коэфициент спада волны
        _Offset, /// Метод задания фазы
        _CurrentPhase, /// Текущий номер фазы
        _Time; //// Время текущей фазы
    int
        _DescrFreq; /// частота дискретизации сигнала
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
