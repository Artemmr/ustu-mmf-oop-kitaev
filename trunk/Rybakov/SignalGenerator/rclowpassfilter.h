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
    void UpdateAlpha();

    SignalGenerator* source;

    double uout;
    int DiscrFreq;
    double
        Alpha,
        RC;
};

#endif // RCLOWPASSFILTER_H
