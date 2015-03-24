#ifndef SIGNALMIXER_H

#define SIGNALMIXER_H

#include <QString>
#include <vector>

#include "signalgenerator.h"

class SignalMixer : public SignalGenerator
{ /// Микшер
public:
    SignalMixer();
    ///public signalgenerator
    double GetSample();                                 /// метод получения последующего сэмпла от генератора
    Result SetFrequency(double iFrequency);             /// метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude);               /// метод задания амплитуды генерируемого сигнала
    Result SetOffset(double iOffset);                   /// метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition();                               /// метод сброса текущего времени
    Result SetDiscretizationFrequency(int iDescrFreq);  /// метод задания частоты дискретизации сигнала

    ///public signalmixer

protected:
    double
        _Pos,                           /// Позиция в текущей фазе
        _DescrFreq,                     /// частота дискретизации сигнала
        _Offset,                        /// Сдвиг  фазы
        _Amplitude,                     /// Амлитуда сигнала
        _Frequency,                     /// частота сигнала
        _InverseFrequency,              /// Период, как обратная величина к частоте сигнала
        _value;                         /// возвращение значения
    int
        _INSignal[];                    /// Массив входящих сигналов


};

#endif // SIGNALMIXER_H
