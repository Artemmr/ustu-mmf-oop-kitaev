#include "trapezioidwavegenerator.h"

TrapezioidWaveGenerator::TrapezioidWaveGenerator(){
    _DescrFreq = 1;         /// Частота дискретизации 1000 Гц
    _Frequency = 0.02;      /// Частота сигнала по-умолчанию 50 Гц
    _Amplitude = 50;        /// Амлитуда сигнала
    _Offset = 0.0;          /// Метод задания фазы
    SetRiseTime(40);        /// Время нарастания [c]
    SetFallTime(50);        /// Время спада [c]
    SetTopPeakTime(60);     /// Время верхнего пика [c]
    SetBotPeakTime(40);     /// Время нижнего пика [c]
    _Pos = 0.0;             /// Позиция в каждой фазе
    _value = 0.0;           /// Текущее положение точки на dr графика
    _CurrentPhase = 0;      /// изначальнно фаза в нуле
}

//public signalgenerator
double TrapezioidWaveGenerator::GetSample(){ ///метод получения последующего сэмпла от генератора

    switch (_CurrentPhase){
        case 0:
            _value = (-_Amplitude)*(1.0-_Pos*_InverseRiseTime)+_Amplitude*(_Pos*_InverseRiseTime);
            _Pos++;
            if (_Pos > _RiseTime) {
                _CurrentPhase = 1;
                _Pos = 0;
            }
            return _value;
            break;

        case 1:
            _value = _Amplitude;
            _Pos++;
            if (_Pos > _TopPeakTime) {
                _CurrentPhase = 2;
                _Pos = 0;
            }
            return _value;
            break;

        case 2:
            _value = _Amplitude*(1.0-_Pos*_InverseFallTime)-_Amplitude*(_Pos*_InverseFallTime);
            _Pos++;
            if (_Pos > _FallTime) {
                _CurrentPhase = 3;
                _Pos = 0;
            }
            return _value;
            break;

        case 3:
            _value = -_Amplitude;
            _Pos++;
            if (_Pos > _BotPeakTime) {
                _CurrentPhase = 0;
                _Pos = 0;
            }
            return _value;
            break;

        /*старый кусочег
        case 0: ///нарастание
            _value = (-_Amplitude)*(1.0-_Pos*_InverseRiseTime)+_Amplitude*(_Pos*_InverseRiseTime); /// формулка для кривой безье по двум точкам
            if(_Pos > _RiseTime){
                _CurrentPhase = 1;
                _Pos -= _RiseTime;
            }
            return _value;
            break;

        case 1: ///верхний пик
            _value = _Amplitude;
            if(_Pos > _PeakTime){
                _CurrentPhase = 2;
                _Pos -= _PeakTime;
            }
            return _value;
            break;

        case 2: ///спад
            _value = _Amplitude*(1.0-_Pos*_InverseFallTime)-_Amplitude*(_Pos*_InverseFallTime);
            if(_Pos>_FallTime){
                _CurrentPhase = 3;
                _Pos -= _FallTime;
            }
            return _value;
            break;

        case 3: ///нижний пик
            default:
            _value = -_Amplitude;
            if(_Pos>(1.0/_Frequency)-_RiseTime-_PeakTime-_FallTime){
                _CurrentPhase = 0;
                _Pos -= (1.0/_Frequency)-_RiseTime-_PeakTime-_FallTime;
            }
            return _value;
            break;
            */
    }
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFrequency(double iFrequency){ /// метод задания частоты генерируемого сигнала
    if (iFrequency<=0) {
        return BadValue;
    }
    _Frequency = iFrequency;
    return Success;
}

void TrapezioidWaveGenerator::SetAmplitude(double iAmplitude){ /// метод задания амплитуды генерируемого сигнала
    _Amplitude = iAmplitude;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetOffset(double iOffset){ /// метод задания сдвига фазы относительно начала отсчёта по времени
    if (iOffset<0) {
        return BadValue;
    }
    _Offset = iOffset;
    return Success;
}

void TrapezioidWaveGenerator::ResetPosition(){ /// метод сброса текущего времени
}

SignalGenerator::Result TrapezioidWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    if (iDescrFreq<=0) {
        return BadValue;
    }
    _DescrFreq = iDescrFreq;
    return Success;
}

///public trapezioidwavegenerator
SignalGenerator::Result TrapezioidWaveGenerator::SetRiseTime(double iRiseTime){ /// Время нарастания сигнала (обратная величина)
    if (iRiseTime<=0) {
        return BadValue;
    }

    _RiseTime =  iRiseTime;
    _InverseRiseTime = 1.0/_RiseTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFallTime(double iFallTime){ /// Время спада сигнала (обратная величина)
    if (iFallTime<=0) {
        return BadValue;
    }

    _FallTime =  iFallTime;
    _InverseFallTime = 1.0/_FallTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetTopPeakTime(double iTopPeakTime){ ///время на пике
    if (iTopPeakTime<=0) {
        return BadValue;
    }
    _TopPeakTime = iTopPeakTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetBotPeakTime(double iBotPeakTime){ ///время на пике
    if (iBotPeakTime<=0) {
        return BadValue;
    }
    _BotPeakTime = iBotPeakTime;
    return Success;
}
