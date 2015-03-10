#include "signalmixer.h"

SignalMixer::SignalMixer()
{

}

double SignalMixer::GetSample(){ ///метод получения последующего сэмпла от генератора

    return 0.0;
}

SignalGenerator::Result SignalMixer::SetFrequency(double iFrequency){ /// метод задания частоты генерируемого сигнала
    if (iFrequency <= 0) {
        return BadValue;
    }
    _Frequency = iFrequency;
    _InverseFrequency = (1.0/_Frequency);
    return Success;
}

void SignalMixer::SetAmplitude(double iAmplitude){ /// метод задания амплитуды генерируемого сигнала
    _Amplitude = iAmplitude;
}

SignalGenerator::Result SignalMixer::SetOffset(double iOffset){ /// метод задания сдвига фазы относительно начала отсчёта по времени
    if (iOffset < 0.0) {
        return BadValue;
    }
    _Offset = iOffset;
    return Success;
}

void SignalMixer::ResetPosition(){ /// метод сброса текущего времени
    _Pos = 0;
}


SignalGenerator::Result SignalMixer::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    if (iDescrFreq <= 0) {
        return BadValue;
    }
    _DescrFreq = iDescrFreq;
    return Success;
}
