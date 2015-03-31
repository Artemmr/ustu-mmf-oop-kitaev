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

    ///�������� �������� �������
    bool AddSignalSource(SignalGenerator *iSource);
    ///������� �������� �������
    bool RemoveSignalSource(SignalGenerator *iSource);
    ///���������� true, ���� ����� �������� ��� ���������
    bool ContainsSignalSource(SignalGenerator *iSource);

signals:
    void UpdateOutput();

private:
    void UpdateKnobs();

    QGridLayout *_glay;

    ///��������� �������, ������������ � �������
    std::vector<SignalGenerator*> _sources;
    ///������ ������������� �������� ��� ����������
    std::vector<double> _sourcesAmps;

    std::vector<QDial*> _sourceDials;
    std::vector<QLabel*> _sourceLabels;

    QDial *_CommonDial;

    QLabel *_CommonLabel;

    double _masterAmp;
private slots:
    ///���� ��� ��������� ��������� ��������� �����������
    void knobValueChanged(int value);
};

#endif // SIGNALMIXER_H
