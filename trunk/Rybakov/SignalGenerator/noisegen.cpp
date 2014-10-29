#include "noisegen.h"
#include <math.h>
NoiseGen::NoiseGen()
{
    Frequency = 20;
    Amplitude = 1.0;
    Offset = 0.0;
    DiscrFreq = 1000;

    position = 0.0;
}

double NoiseGen::GetSample()
{

    return 0;
}

void NoiseGen::SetFrequency(double iFrequency)
{
    Frequency = iFrequency;
}

void NoiseGen::SetAmplitude(double iAmplitude)
{
    Amplitude = iAmplitude;
}

void NoiseGen::SetOffset(double iOffset)
{
    Offset = iOffset;
}

void NoiseGen::ResetPosition()
{
    position = 0.0;
}

void NoiseGen::SetDiscrFrequency(int iDiscrFreq)
{
    DiscrFreq = iDiscrFreq;
}
