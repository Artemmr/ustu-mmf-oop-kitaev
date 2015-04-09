#ifndef TRIANGLEWAVEGENERATOR_H
#define TRIANGLEWAVEGENERATOR_H

#include "signalgenerator.h"

class TriangleWaveGenerator : public SignalGenerator
{
public:
    TriangleWaveGenerator();
    virtual double GetSample();
    virtual void ResetPosition();
    virtual void SetAmplitude(double iAmplitude);
    virtual void SetFrequency(double iFrequency);
    virtual void SetOffset(double iOffset);
    virtual void SetDiscretizationFrequency(int iDescrFreq);

    void SetRiseTime(double iRiseTime);
    void SetFallTime(double iFallTime);

protected:
    double
        _value,
        _Amplitude,
        _Frequency,
        _PhaseShift,
        _RiseTime,
        _FallTime,
        _Offset,
        _DiscrFreq,
        _Pos;
    unsigned short int
        _CurrentPhase;
};

#endif // TRIANGLEWAVEGENERATOR_H
