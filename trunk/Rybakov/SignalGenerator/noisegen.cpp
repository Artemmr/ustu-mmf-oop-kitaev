#include "noisegen.h"

NoiseGen::NoiseGen(){
    Frequency = 20;
    Amplitude = 0;
    Offset = 0;
    DescrFreq = 1000;
}

double NoiseGen::GetSample(){
return 0;
}

void NoiseGen::SetFrequency(double iFrequency){
    Frequency = iFrequency;
}

void NoiseGen::SetAmplitude(double iAmplitude){
    Amplitude = iAmplitude;
}

void NoiseGen::SetOffset(double iOffset){
    Offset = iOffset;
}

void NoiseGen::ResetPosition(){

}

void NoiseGen::SetDiscrFrequency(int iDescrFreq){

}
