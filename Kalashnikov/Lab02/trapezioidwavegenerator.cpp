#include <trapezioidwavegenerator.h>

TrapezioidWaveGenerator::TrapezioidWaveGenerator(){
    _DescrFreq = 1000; /// Частота дискретизации 1000 Гц
    _Frequency = 50;   /// Частота сигнала по-умолчанию 50 Гц
    _Position = 0;     /// номер сэмпла
    _Amplitude = 1;    /// Амлитуда сигнала
    _Offset = 0;       /// Метод задания фазы
    _CurrentPhase = 0; /// Текущий номер фазы
}

//public signalgenerator
double TrapezioidWaveGenerator::GetSample(){ ///метод получения последующего сэмпла от генератора

    switch (_CurrentPhase){

        case 0:
            double value = _Amplitude* f(_Time);
            if(_Time>_RizeTime){
                _CurrentPhase = 1;
                _Time -= _RizeTime;
            }
            return value;
            break;

        case 1:
            double value = _Amplitude*f(_Time);
            if(_Time>_PeakTime){
                _CurrentPhase = 2;
                _Time -= _PeakTime;
            }
            return value;
            break;

        case 2:
            double value = _Amplitude*f(_Time);
            if(_Time>_FallTime){
                _CurrentPhase = 3;
                _Time -= _FallTime;
            }
            return value;
            break;

        case 3:
            default:
            double value = -_Amplitude*f(_Time);
            if(_Time>(1.0/_Frequency)-_RizeTime-_PeakTime-_FallTime){
                _CurrentPhase = 0;
                _Time -= (1.0/_Frequency)-_RizeTime-_PeakTime-_FallTime;
            }
            return value;
            break;
    }
}

void TrapezioidWaveGenerator::SetFrequency(double iFrequency){ /// метод задания частоты генерируемого сигнала
    _frequency = iFrequency;
}

void TrapezioidWaveGenerator::SetAmplitude(double iAmplitude){ /// метод задания амплитуды генерируемого сигнала
    _amplitude = iAmplitude;
}

void TrapezioidWaveGenerator::SetOffset(double iOffset){ /// метод задания сдвига фазы относительно начала отсчёта по времени
    _Offset = iOffset;
}

void TrapezioidWaveGenerator::ResetPosition(){ /// метод сброса текущего времени
    _Position = 0.0;
}

void TrapezioidWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    _DescrFreq = iDescrFreq;
}

///public trapezioidwavegenerator
void TrapezioidWaveGenerator::SetRizeTime(double iRizeTime){ /// Время нарастания сигнала
    _RizeTime = iRizeTime;
}

void TrapezioidWaveGenerator::SetFallTime(double iFallTime){ /// Время спада сигнала.
    _FallTime = iFallTime;
}

void TrapezioidWaveGenerator::SetPeakTime(double iPeakTime){ ///время на пике
    _PeakTime = iPeakTime;
}
