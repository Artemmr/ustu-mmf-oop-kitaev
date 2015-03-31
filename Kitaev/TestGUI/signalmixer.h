#ifndef SIGNALMIXER_H
#define SIGNALMIXER_H

#include "signalgenerator.h"

#include <QWidget>

#include <vector>

class QDial;
class QGridLayout;
class QLabel;

class SignalMixer: public QWidget, public SignalGenerator
{
    Q_OBJECT
public:
    explicit SignalMixer(QWidget *iParent = 0);

    virtual double GetSample();
    virtual void SetFrequency(double iFrequency){}
    virtual void SetAmplitude(double iAmplitude){}
    virtual void SetOffset(double iOffset){}
    virtual void ResetPosition();
    virtual void SetDiscretizationFrequency(int iDescrFreq);

    ///Добавить источник сигнала
    bool AddSignalSource(SignalGenerator *iSource);
    ///Удалить источник сигнала
    bool RemoveSignalSource(SignalGenerator *iSource);
    ///Возвращает true, если такой источник уже подключен
    bool ContainsSignalSource(SignalGenerator *iSource);

signals:
    void UpdateOutput();

private:
    void UpdateKnobs();

    QGridLayout *_glay;

    ///Источники сигнала, подключенные к микшеру
    std::vector<SignalGenerator*> _sources;
    ///Массив коэффициентов усиления для источников
    std::vector<double> _sourcesAmps;

    std::vector<QDial*> _sourceDials;
    std::vector<QLabel*> _sourceLabels;

    QDial *_CommonDial;

    QLabel *_CommonLabel;

    double _masterAmp;
private slots:
    ///Слот для обработки изменения положения регуляторов
    void knobValueChanged(int value);
};

#endif // SIGNALMIXER_H
