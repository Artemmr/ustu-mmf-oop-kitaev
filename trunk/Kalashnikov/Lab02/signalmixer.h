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
    double GetSample();                                             /// метод получения последующего сэмпла от генератора
    Result SetFrequency(double /*iFrequency*/){return Success;}     /// метод задания частоты генерируемого сигнала
    void SetAmplitude(double /*iAmplitude*/){}                      /// метод задания амплитуды генерируемого сигнала
    Result SetOffset(double /*iOffset*/){return Success;}           /// метод задания сдвига фазы относительно начала отсчёта по времени
    void ResetPosition();                                           /// метод сброса текущего времени
    Result SetDiscretizationFrequency(int iDescrFreq);              /// метод задания частоты дискретизации сигнала

    ///public signalmixer
    Result AddSignalSource (SignalGenerator *iSource);              /// Добавляем генератор сигнала
    Result ContainsSignalSource (SignalGenerator *iSource);         /// Проверка на дубли
    Result RemoveSignalSource (SignalGenerator *iSource);           /// Убираем генератор сигнала

private:
    std::vector<SignalGenerator*> _Source;                          /// коллекция входящих сигналов

    double _masterAmp;

///private slots:


};

#endif // SIGNALMIXER_H
