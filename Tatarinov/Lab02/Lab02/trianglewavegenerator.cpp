#include "trianglewavegenerator.h"

TriangleWaveGenerator::TriangleWaveGenerator(){
    _DiscrFreq = 1000.0;
    _Amplitude = 100.0;
    _Offset = 0.0;
    _RiseTime = 5.0;
    _FallTime = 6.0;
    _Frequency = 10.0;
    _value = 0.0;
    _CurrentPhase = 0;
    _Pos = 0.0;
}

double TriangleWaveGenerator::GetSample(){
    switch (_CurrentPhase) {
    case 0:
        _value = (-_Amplitude)*(1.0-_Pos/_RiseTime)+_Amplitude*(_Pos/_RiseTime);
        _Pos += 1/_Frequency;
        if (_Pos > _RiseTime){
            _CurrentPhase = 1;
            _Pos -= _RiseTime;
        }
        return _value;
        break;
    case 1:
        _value = _Amplitude*(1.0-_Pos/_FallTime)-_Amplitude*(_Pos/_FallTime);
        _Pos += 1/_Frequency;
        if (_Pos > _FallTime){
            _CurrentPhase = 0;
            _Pos -= _FallTime;
        }
        return _value;
        break;
    }
}
void TriangleWaveGenerator::ResetPosition(){
    _value = 0;
}
void TriangleWaveGenerator::SetAmplitude(double iAmplitude){
    _Amplitude = iAmplitude;
}
void TriangleWaveGenerator::SetFrequency(double iFrequency){
    _Frequency = iFrequency;
}
void TriangleWaveGenerator::SetOffset(double iOffset){
    _Offset = iOffset;
}
void TriangleWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){
    _DiscrFreq = iDescrFreq;
}

void TriangleWaveGenerator::SetRiseTime(double iRiseTime){
    _RiseTime = iRiseTime;
}
void TriangleWaveGenerator::SetFallTime(double iFallTime){
    _FallTime = iFallTime;
}
