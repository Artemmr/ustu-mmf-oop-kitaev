#ifndef RCLOWPASSFILTER_H
#define RCLOWPASSFILTER_H

#include "signalgenerator.h"

class RCLOWPASSFILTER : public SignalGenerator {

public:
    RCLOWPASSFILTER();

    double GetSample();                                 /// получения последующего сэмпла от генератора
    void ResetPosition();                               /// сброс текущего времени
    void SetAmplitude(double iAmplitude);               /// задание амплитуды генерируемого сигнала
    Result SetFrequency(double iFrequency);             /// задание частоты генерируемого сигнала
    Result SetOffset(double iOffset);                   /// задание сдвига фазы относительно начала отсчёта по времени
    Result SetDiscretizationFrequency(int iDescrFreq);  /// задание частоты дискретизации сигнала

    bool SetSource(SignalGenerator *iSource);

    void SetRC(double iRC);

private:
    void UpdateAlpha();

    SignalGenerator* source;


    int DescrFreq;
    double
        Alpha,
        uout,
        RC;
};

#endif // RCLOWPASSFILTER_H
