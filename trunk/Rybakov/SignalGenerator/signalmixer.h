#ifndef SIGNALMIXER_H
#define SIGNALMIXER_H

#include <vector>
#include <QWidget>

#include "signalgenerator.h"

class QLabel;
class QDial;
class QGridLayout;

class SignalMixer : public QWidget, public SignalGenerator
{
    Q_OBJECT
public:
    explicit SignalMixer(QWidget *iParent = 0);
    virtual double GetSample(void);                 // метод получения последующего сэмпла от генератора
    virtual void SetFrequency(double ){}            // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double ){}            // метод задания амплитуды генерируемого сигнала
    virtual void SetOffset(double ){}               // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                   // метод сброса текущего времени
    virtual void SetDiscretizationFrequency(int iDescrFreq); // метод задания частоты дискретизации сигнала

    //Добавление источника
    bool AddSource(SignalGenerator *iSource);
    //Удаление источника
    bool RemoveSource(SignalGenerator *iSource);
    //Проверка на наличие источника
    bool CheckSource(SignalGenerator *iSource);

signals:
    void UpdateOutput();

private:
    void UpdateDials();
    //Сеть элементов
    QGridLayout *GridLay;

    //Источники
    std::vector<SignalGenerator*> sources;
    std::vector<double> sourcesAmps;

    std::vector<QLabel*> sourcesLabels;
    std::vector<QDial*> sourcesDials;

    QLabel *masterLabel;
    QDial *masterDial;
    double masterAmp;
    double dialsCoeficient;
private slots:
    void DialValueChanged(int value);
};

#endif // SIGNALMIXER_H
