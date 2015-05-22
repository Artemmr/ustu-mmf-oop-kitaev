#ifndef TRAPEZIOIDWAVEGENERATOR_H

#define TRAPEZIOIDWAVEGENERATOR_H

#include "signalgenerator.h"

class TrapezioidWaveGenerator : public SignalGenerator {
    /// трапецеидальный сигнал
public:
    TrapezioidWaveGenerator();
    ///public signalgenerator
    virtual double GetSample();                                 ///метод получения последующего сэмпла от генератора
    virtual Result SetFrequency(double iFrequency);             /// метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude);               /// метод задания амплитуды генерируемого сигнала
    virtual Result SetOffset(double iOffset);                   /// метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                               /// метод сброса текущего времени
    virtual Result SetDiscretizationFrequency(int iDescrFreq);  /// метод задания частоты дискретизации сигнала

    ///public trapezioidwavegenerator
    Result SetRiseTime(double iRiseTime);               /// Время нарастания
    Result SetFallTime(double iFallTime);               /// Время спада
    Result SetTopPeakTime(double iTopPeakTime);         /// Время на верхнем пике
    Result SetBotPeakTime(double iBotPeakTime);         /// Время на нижнем пике

    virtual QString GetName();

protected:
    double
        _value,                         /// Возвращения значения
        _Amplitude,                     /// Амлитуда сигнала
        _Frequency,                     /// частота сигнала
        _InverseFrequency,              /// Период, как обратная величина к частоте сигнала
        _PhaseShift,                    /// смещение фазы сигнала
        _RiseTime,                      /// коэфициент нагнетания волны
        _InverseRiseTime,               /// для удобства подстановки
        _TopPeakTime,                   /// Скважность, время пика сколько идёт на верху
        _BotPeakTime,                   /// Скважность, время пика сколько идёт на низу
        _FallTime,                      /// коэфициент спада волны
        _InverseFallTime,               /// для удобства подстановки
        _Offset,                        /// Сдвиг  фазы
        _DescrFreq,                     /// частота дискретизации сигнала
        _Pos;                           /// Позиция в текущей фазе
    int
        _CurrentPhase,                  /// Текущий номер фазы
        _Number;
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
