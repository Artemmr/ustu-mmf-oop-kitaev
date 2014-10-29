#include "noisegen.h"
#include <math.h>
#include <stdlib.h>     //srand, rand
#include <time.h>       //time
NoiseGen::NoiseGen()
{
    Frequency = 20;
    Amplitude = 1.0;
    Offset = 0.0;
    DiscrFreq = 1000;

    position = 0.0;
    srand(time(0));
}

double NoiseGen::GetSample()
{
    //double x = (double)rand()/RAND_MAX;
    //srand(time(0));
    return ((double)rand()/RAND_MAX-0.5)*2*Amplitude;
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
