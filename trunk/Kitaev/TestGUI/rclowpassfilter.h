#ifndef RCLOWPASSFILTER_H
#define RCLOWPASSFILTER_H

#include "signalgenerator.h"

class RCLowPassFilter:public SignalGenerator
{
public:
    RCLowPassFilter();

    virtual double GetSample();
    virtual void SetFrequency(double iFrequency);
    virtual void SetAmplitude(double iAmplitude);
    virtual void SetOffset(double iOffset);
    virtual void ResetPosition();
    virtual void SetDiscretizationFrequency(int iDescrFreq);

    bool SetSource(SignalGenerator *iSource);

    void SetRC(double iRC);

private:
    void UpdateAlfa();///����� ��������� �������� _alfa

    SignalGenerator* _source;

    double _uout;

    int
        _discrFreq;///������� ������������� �������

    double
        _alfa,///��������� RC-�������
        _RC;///�������� RC

};

#endif // RCLOWPASSFILTER_H
