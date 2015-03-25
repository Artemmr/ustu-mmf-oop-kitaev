#include "signalmixer.h"

SignalMixer::SignalMixer()
{

}

double SignalMixer::GetSample(){ ///метод получения последующего сэмпла от генератора
    std::vector<double> new_samples(_Source.size());

    for(unsigned int i = 0; i < _Source.size(); ++i)
        new_samples[i] = _Source[i]->GetSample();

    double summ = 0.0;
    for(unsigned int i = 0; i < _Source.size(); ++i)
        summ+=new_samples[i]; ///TODO необходимо добавить коэфф усиления для каждого источника
    summ/=new_samples.size(); ///TODO Необходимо добавить коэфф усиления на выходе

    return summ*_masterAmp;
}


void SignalMixer::ResetPosition(){ /// метод сброса текущего времени
    for (unsigned int i = 0; i < _Source.size(); ++i)
        _Source[i]->ResetPosition();
}

SignalGenerator::Result SignalMixer::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    for (unsigned int i = 0; i < _Source.size(); ++i)
        _Source[i]->SetDiscretizationFrequency(iDescrFreq);
    return Success;
}

SignalGenerator::Result SignalMixer::AddSignalSource(SignalGenerator *iSource){ /// Добавляем генератор сигнала
    if (iSource == 0) //
        return BadValue;
    if (ContainsSignalSource(iSource))
        return BadValue;
    _Source.push_back(iSource);
    return Success;
}

SignalGenerator::Result SignalMixer::ContainsSignalSource(SignalGenerator *iSource){/// Проверка на дубли
    for (unsigned int i = 0; i < _Source.size(); ++i)
        if (_Source[i] == iSource)
            return Success;
    return BadValue;
}

SignalGenerator::Result SignalMixer::RemoveSignalSource(SignalGenerator *iSource){/// Убираем генератор сигнала
    if(!ContainsSignalSource(iSource))
        return BadValue;
    return Success;
}
