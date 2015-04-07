#include "ngen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

NGen::NGen()
{
    _Frequency = 20;
    _Amplitude = 1.0;
    _Offset = 0.0;
    _DiscrFreq = 1000;

    _Pos = 0.0;
    srand(time(0));
}

double NGen::GetSample(){
    return ((double)rand()/RAND_MAX-0.5)*2*_Amplitude;
}
void NGen::SetFrequency(double iFrequency){
    _Frequency = iFrequency;
}
void NGen::SetAmplitude(double iAmplitude){
    _Amplitude = iAmplitude;
}
void NGen::SetOffset(double iOffset){
    _Offset = iOffset;
}
void NGen::ResetPostion(){
    _Pos = 0.0;
}
void NGen::SetDescretizationFrequency(int iDiscrFreq){
    _DiscrFreq = iDiscrFreq;
}
