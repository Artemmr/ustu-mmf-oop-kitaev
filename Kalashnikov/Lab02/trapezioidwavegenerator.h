#ifndef TRAPEZIOIDWAVEGENERATOR_H

#define TRAPEZIOIDWAVEGENERATOR_H

#include "signalgenerator.h"

class TrapezioidWaveGenerator : public SignalGenerator
{ // трапецеидальный сигнал
public:
    TrapezioidWaveGenerator();
    //public signalgenerator
    double GetSample();                                 ///метод получения последующего сэмпла от генератора
    Result SetFrequency(double iFrequency);             /// метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude);               /// метод задания амплитуды генерируемого сигнала
    Result SetOffset(double iOffset);                   /// метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition();                               /// метод сброса текущего времени
    Result SetDiscretizationFrequency(int iDescrFreq);  /// метод задания частоты дискретизации сигнала

    //public trapezioidwavegenerator
    Result SetRiseTime(double iRiseTime);               /// Время нарастания
    Result SetFallTime(double iFallTime);               /// Время спада
    Result SetPeakTime(double iPeakTime);               /// Время на пике

protected:
    double
        _value,                 ///+ Возвращения значения
        _Amplitude,             ///+ Амлитуда сигнала
        _Frequency,             ///+ частота сигнала
        _PhaseShift,            /// смещение фазы сигнала
        _RiseTime,              /// коэфициент нагнетания волны
        _InverseRiseTime,       /// для удобства подстановки
        _PeakTime,              /// Скважность, время пика сколько идёт
        _FallTime,              /// коэфициент спада волны
        _InverseFallTime,       /// для удобства подстановки
        _Offset,                /// Метод задания фазы
        _Time;                  /// Время текущей фазы
    int
        _Position,              /// количество колебаний
        _CurrentPhase,          /// Текущий номер фазы
        _DescrFreq;             /// частота дискретизации сигнала
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
