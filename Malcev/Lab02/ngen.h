#ifndef NGEN_H
#define NGEN_H

#include "signalgenerator.h"


class NGen : public SignalGenerator
{
public:
    NGen();
    double GetSample();
    void SetFrequency(double iFrequency);
    void SetAmplitude(double iAmplitude);
    void SetOffset(double iOffset);
    void ResetPostion();
    void SetDescretizationFrequency(int iDiscrFreq);
protected:
    double
        _Frequency,
        _Amplitude,
        _Offset;
    int
        _DiscrFreq,
        _Counter;
    unsigned int
        _Pos;

};

#endif // NGEN_H
