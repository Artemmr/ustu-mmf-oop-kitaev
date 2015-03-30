#include <QLabel>
#include <QDial>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "signalmixer.h"

SignalMixer::SignalMixer(QWidget *iParent):
    QWidget(iParent)
{
    _masterAmp = 1.0;

    QHBoxLayout *_hblay = new QHBoxLayout (this);

    QWidget *commonDialWidget;
    _hblay->addWidget(commonDialWidget = new QWidget (this));
    { /// здесь читерство с областью видимости
        QWidget *parent = commonDialWidget;
        QVBoxLayout *vlay = new QVBoxLayout (parent);
        vlay->addWidget(new QLabel("Master", parent));
        vlay->addWidget(_CommonDial = new QDial (this));
    }
    connect(_CommonDial, SIGNAL(valueChanged(int)), this, SLOT(knobValueChanged(int)));
}

double SignalMixer::GetSample(){ ///метод получения последующего сэмпла от генератора
    std::vector<double> new_samples(_Source.size());

    for(unsigned int i = 0; i < _Source.size(); ++i)
        new_samples[i] = _Source[i]->GetSample();

    double summ = 0.0;
    for(unsigned int i = 0; i < _Source.size(); ++i)
        summ+=new_samples[i];                       ///TODO необходимо добавить коэфф усиления для каждого источника
    summ/=new_samples.size();                       ///TODO Необходимо добавить коэфф усиления на выходе

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
    if (ContainsSignalSource(iSource) == Success)
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

void SignalMixer::knobValueChanged(int value){
    if (QObject::sender()==_CommonDial){
        _masterAmp = _CommonDial->value()/50.0; ///передлать, если нужно /// и толку? 1 делал, 50, 100, 1000
    }
}
