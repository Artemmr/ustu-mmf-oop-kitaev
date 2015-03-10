#ifndef SIGNALMIXER_H

#define SIGNALMIXER_H

#include "signalgenerator.h"

class SignalMixer : public SignalGenerator
{ /// Микшер
public:
    SignalMixer();
    ///public signalgenerator
    double GetSample();                                 ///метод получения последующего сэмпла от генератора
    Result SetFrequency(double iFrequency);             /// метод задания частоты генерируемого сигнала
    void SetAmplitude(double iAmplitude);               /// метод задания амплитуды генерируемого сигнала
    Result SetOffset(double iOffset);                   /// метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition();                               /// метод сброса текущего времени
    Result SetDiscretizationFrequency(int iDescrFreq);  /// метод задания частоты дискретизации сигнала

    ///public signalmixer


protected:

};

#endif // SIGNALMIXER_H
