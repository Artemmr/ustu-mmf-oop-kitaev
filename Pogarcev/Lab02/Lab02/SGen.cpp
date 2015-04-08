#include "SGen.h"
#include <math.h>

SGen::SGen(){
    _DiscrFreq = 1000;
    _Frequency = 50.0;
    _Amplitude = 1.0;
    _PhaseShift = 0.0;
    _Pos = 0;
}

double SGen::GetSample(){
    double result = _Amplitude*sin(_Pos*_Frequency*2*M_PI/((double)_DiscrFreq))+_PhaseShift;
    _Pos++;
    return result;
}
void SGen::SetFrequency(double iFrequency){
    _Frequency = iFrequency;
}
void SGen::SetAmplitude(double iAmplitude){
    _Amplitude = iAmplitude;
}
void SGen::SetOffset(double iOffset){
    _PhaseShift = iOffset;
}
void SGen::ResetPosition(){
    _Pos = 0;
}
void SGen::SetDiscretizationFrequency(int iDiscrFreq){
    _DiscrFreq = iDiscrFreq;
}
