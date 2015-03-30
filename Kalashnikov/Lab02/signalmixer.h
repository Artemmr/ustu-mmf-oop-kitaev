#ifndef SIGNALMIXER_H

#define SIGNALMIXER_H

#include <QString>
#include <vector>
#include <QWidget>

#include "signalgenerator.h"

class QDial;

class SignalMixer : public QWidget, public SignalGenerator
{ /// Микшер
    Q_OBJECT
public:
    explicit SignalMixer(QWidget *iParent =0);
    ///public signalgenerator
    virtual double GetSample();                                             /// метод получения последующего сэмпла от генератора
    virtual Result SetFrequency(double /*iFrequency*/){return Success;}     /// метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double /*iAmplitude*/){}                      /// метод задания амплитуды генерируемого сигнала
    virtual Result SetOffset(double /*iOffset*/){return Success;}           /// метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                                           /// метод сброса текущего времени
    virtual Result SetDiscretizationFrequency(int iDescrFreq);              /// метод задания частоты дискретизации сигнала

    ///public signalmixer
    Result AddSignalSource (SignalGenerator *iSource);              /// Добавляем генератор сигнала
    Result ContainsSignalSource (SignalGenerator *iSource);         /// Проверка на дубли
    Result RemoveSignalSource (SignalGenerator *iSource);           /// Убираем генератор сигнала

private:
    std::vector<SignalGenerator*> _Source;                          /// коллекция входящих сигналов

    double _masterAmp;

    QDial *_CommonDial;
///private slots:
private slots:
    void knobValueChanged(int value);


};

#endif // SIGNALMIXER_H
