#include "noisegenerator.h"
#include <math.h>
#include <stdlib.h>     //srand, rand
#include <time.h>       //time
NoiseGenerator::NoiseGenerator()
{
    Frequency = 20;
    Amplitude = 1.0;
    Offset = 0.0;
    DiscrFreq = 1000;

    position = 0.0;
    srand(time(0));

    static int globalNoiseGeneratorNumber = 0;
    number = globalNoiseGeneratorNumber++;
}

double NoiseGenerator::GetSample()
{
    //double x = (double)rand()/RAND_MAX;
    //srand(time(0));
    return ((double)rand()/RAND_MAX-0.5)*2*Amplitude;
}

NoiseGenerator::Result NoiseGenerator::SetFrequency(double iFrequency)
{
    Frequency = iFrequency;
    return Success;
}

void NoiseGenerator::SetAmplitude(double iAmplitude)
{
    Amplitude = iAmplitude;
}

NoiseGenerator::Result NoiseGenerator::SetOffset(double iOffset)
{
    Offset = iOffset;

    return Success;
}

void NoiseGenerator::ResetPosition()
{
    position = 0.0;
}

NoiseGenerator::Result NoiseGenerator::SetDiscretizationFrequency(int iDescrFreq)
{
    DiscrFreq = iDescrFreq;
    return Success;
}

QString NoiseGenerator::GetName()
{
    return "Noise "+QString::number(number);
}
