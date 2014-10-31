#include <trapezioidwavegenerator.h>

TrapezioidWaveGenerator::TrapezioidWaveGenerator(){

}

//public signalgenerator
double TrapezioidWaveGenerator::GetSample(){ //метод получения последующего сэмпла от генератора

}

void TrapezioidWaveGenerator::SetFrequency(double iFrequency){ // метод задания частоты генерируемого сигнала
    _frequency = iFrequency;
}

void TrapezioidWaveGenerator::SetAmplitude(double iAmplitude){ // метод задания амплитуды генерируемого сигнала
    _amplitude = iAmplitude;
}

void TrapezioidWaveGenerator::SetOffset(double iOffset){ // метод задания сдвига фазы относительно начала отсчёта по времени

}

void TrapezioidWaveGenerator::ResetPosition(){ // метод сброса текущего времени
    _position = 0.0;
}

void TrapezioidWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){ // метод задания частоты дискретизации сигнала
    _DescrFreq = iDescrFreq;
}

//public trapezioidwavegenerator
void TrapezioidWaveGenerator::SetRizePeriod(double iRizePeriod){ // Метод/функция нарастания/фронта сигнала
    _RizePeriod = iRizePeriod;
}

void TrapezioidWaveGenerator::SetFallPeriod(double iFallPeriod){ // Метод/функция уменьшения/спада сигнала.
    _FallPeriod = iFallPeriod;
}
