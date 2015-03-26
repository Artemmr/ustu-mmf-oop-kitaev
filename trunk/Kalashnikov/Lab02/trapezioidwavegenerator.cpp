#include "trapezioidwavegenerator.h"

TrapezioidWaveGenerator::TrapezioidWaveGenerator(){
    SetDiscretizationFrequency(1000);       /// Частота дискретизации
    SetAmplitude(100);                      /// Амлитуда сигнала
    SetOffset(0.0);                         /// Метод сдвига фазы
    SetRiseTime(5);                         /// Время нарастания [c]
    SetFallTime(6);                         /// Время спада [c]
    SetTopPeakTime(3);                      /// Время верхнего пика [c]
    SetBotPeakTime(2);                      /// Время нижнего пика [c]
    SetFrequency(10);                       /// Зададим частоту
    ResetPosition();                        /// Изначальная позиция нуль и никак иначе :)
    _value = 0.0;                           /// Текущее положение точки на dr графика
    _CurrentPhase = 0;                      /// изначальнно фаза в нуле
}

//public signalgenerator
double TrapezioidWaveGenerator::GetSample(){///метод получения последующего сэмпла от генератора

    switch (_CurrentPhase){
        /// Нагнетание
        case 0:
            _value = (-_Amplitude)*(1.0-_Pos*_InverseRiseTime)+_Amplitude*(_Pos*_InverseRiseTime);
            _Pos += _InverseFrequency;
            if (_Pos > _RiseTime) {
                _CurrentPhase = 1;
                _Pos -= _RiseTime;
            }
            return _value;
            break;
        /// Верхний пик
        case 1:
            _value = _Amplitude;
            _Pos += _InverseFrequency;
            if (_Pos > _TopPeakTime) {
                _CurrentPhase = 2;
                _Pos -= _TopPeakTime;
            }
            return _value;
            break;
        /// Спад
        case 2:
            _value = _Amplitude*(1.0-_Pos*_InverseFallTime)-_Amplitude*(_Pos*_InverseFallTime);
            _Pos += _InverseFrequency;
            if (_Pos > _FallTime) {
                _CurrentPhase = 3;
                _Pos -= _FallTime;
            }
            return _value;
            break;

        /// Нижний пик
        case 3:
            _value = -_Amplitude;
            _Pos += _InverseFrequency;
            if (_Pos > _BotPeakTime) {
                _CurrentPhase = 0;
                _Pos -= _BotPeakTime;
            }
            return _value;
            break;
        default:
        return -1.0;
    }
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFrequency(double iFrequency){ /// метод задания частоты генерируемого сигнала
    if (iFrequency <= 0) {
        return BadValue;
    }
    _Frequency = iFrequency;
    _InverseFrequency = (1.0/_Frequency);
    return Success;
}

void TrapezioidWaveGenerator::SetAmplitude(double iAmplitude){ /// метод задания амплитуды генерируемого сигнала
    _Amplitude = iAmplitude;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetOffset(double iOffset){ /// метод задания сдвига фазы относительно начала отсчёта по времени
    if (iOffset < 0.0) {
        return BadValue;
    }
    _Offset = iOffset;
    return Success;
}

void TrapezioidWaveGenerator::ResetPosition(){ /// метод сброса текущего времени
//    _value = 0;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    if (iDescrFreq <= 0) {
        return BadValue;
    }
    _DescrFreq = iDescrFreq;
    return Success;
}

///public trapezioidwavegenerator
SignalGenerator::Result TrapezioidWaveGenerator::SetRiseTime(double iRiseTime){ /// Время нарастания сигнала (обратная величина)
    if (iRiseTime <= 0) {
        return BadValue;
    }

    _RiseTime =  iRiseTime;
    _InverseRiseTime = 1.0/_RiseTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFallTime(double iFallTime){ /// Время спада сигнала (обратная величина)
    if (iFallTime <= 0) {
        return BadValue;
    }

    _FallTime =  iFallTime;
    _InverseFallTime = 1.0/_FallTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetTopPeakTime(double iTopPeakTime){ ///время на верхнем пике
    if (iTopPeakTime <= 0) {
        return BadValue;
    }
    _TopPeakTime = iTopPeakTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetBotPeakTime(double iBotPeakTime){ ///время на нижнем пике
    if (iBotPeakTime <= 0) {
        return BadValue;
    }
    _BotPeakTime = iBotPeakTime;
    return Success;
}
