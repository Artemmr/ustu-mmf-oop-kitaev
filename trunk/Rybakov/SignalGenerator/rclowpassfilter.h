#ifndef RCLOWPASSFILTER_H
#define RCLOWPASSFILTER_H

#include "SignalGen.h"

class RCLowPassFilter:public SignalGen
{
public:
    RCLowPassFilter();

    virtual double GetSample();
    virtual void SetFrequency(double iFrequency);
    virtual void SetAmplitude(double iAmplitude);
    virtual void SetOffset(double iOffset);
    virtual void ResetPosition();
    virtual void SetDiscrFrequency(int iDescrFreq);

    bool SetSource(SignalGen *iSource);

    void SetRC(double iRC);
private:
    void UpdateAlpha();

    SignalGen* source;

    double uout;
    int DiscrFreq;
    double
        Alpha,
        RC;
};

#endif // RCLOWPASSFILTER_H
