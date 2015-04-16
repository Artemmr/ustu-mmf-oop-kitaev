#include "signalmixer.h"

#include <QLabel>
#include <QDial>
#include <QGridLayout>

SignalMixer::SignalMixer(QWidget *iParent):
    QWidget(iParent)
{
    _masterAmp = 1.0;
    _DialsCoeff = 33.;

    _glay = new QGridLayout(this);

    _CommonLabel = new QLabel("Master", this);
    _CommonDial = new QDial(this);
    _CommonDial->setValue(_masterAmp*_DialsCoeff);

    UpdateKnobs();

    connect(_CommonDial, SIGNAL(valueChanged(int)), this, SLOT(knobValueChanged(int)));
}

void SignalMixer::knobValueChanged(int value)
{
    if(QObject::sender()==_CommonDial)
    {
        ///TODO изменить значение коэфф выходного усиления
        _masterAmp = _CommonDial->value()/_DialsCoeff;///TODO 50 - цифра с потолка, переделать
        emit(UpdateOutput());
        return;
    }
    for(int i = 0; i<_sourceDials.size(); ++i)
    {
        if(QObject::sender()==_sourceDials[i])
        {
            _sourcesAmps[i] = _sourceDials[i]->value()/_DialsCoeff;
            emit(UpdateOutput());
            return;
        }
    }
}

///Добавить источник сигнала
bool SignalMixer::AddSignalSource(SignalGenerator *iSource)
{
    if(iSource==0)
        return false;
    if(ContainsSignalSource(iSource))
        return false;
    _sources.push_back(iSource);
    _sourcesAmps.push_back(1.0);
    _sourceDials.push_back(new QDial(this));
    //_sourceDials[_sourceDials.size()-]->
    _sourceDials.back()->setValue(_sourcesAmps.back()*_DialsCoeff);
    _sourceLabels.push_back(new QLabel(_sources.back()->GetName(),this));
    connect(_sourceDials.back(), SIGNAL(valueChanged(int)), this, SLOT(knobValueChanged(int)));
    UpdateKnobs();
    return true;
}

///Удалить источник сигнала
bool SignalMixer::RemoveSignalSource(SignalGenerator *iSource)
{
    if(!ContainsSignalSource(iSource))
        return false;
    std::vector<SignalGenerator*> new_sources;
    for(unsigned int i = 0; i<_sources.size(); ++i)
        if(_sources[i]!=iSource)
            new_sources.push_back(_sources[i]);
    _sources = new_sources;
    return true;
}

bool SignalMixer::ContainsSignalSource(SignalGenerator *iSource)
{
    for(unsigned int i = 0; i<_sources.size(); ++i)
        if(_sources[i]==iSource)
            return true;
    return false;
}

void SignalMixer::UpdateKnobs()
{
    _glay->removeWidget(_CommonDial);///Убрали общий регулятор из менеджера размещений
    _glay->removeWidget(_CommonLabel);///Убрали подпись общ регулятора из менеджера размещений
    for(int i = 0; i<_sourceDials.size(); ++i)///Убираем все регуляторы каналов
        _glay->removeWidget(_sourceDials[i]);
    for(int i = 0; i<_sourceLabels.size(); ++i)///Убираем все подписи регуляторов каналов
        _glay->removeWidget(_sourceLabels[i]);

    for(int i = 0; i<_sourceLabels.size(); ++i)///Добавляем подписи всех регуляторов каналов
        _glay->addWidget(_sourceLabels[i], 0, i);
    for(int i = 0; i<_sourceDials.size(); ++i)
        _glay->addWidget(_sourceDials[i], 1, i);

    for(int i = 0; i<_sourceDials.size(); ++i)
        _glay->setColumnStretch(i, 0);
    _glay->setColumnStretch(_sourceDials.size(), 1);
    ///TODO new QWidget(this) нужно обработать иначе, чтобы не выделять каждый раз нову память
    _glay->addWidget(new QWidget(this), 0, _sourceDials.size());
    _glay->addWidget(new QWidget(this), 1, _sourceDials.size());

    _glay->addWidget(_CommonLabel, 0, _sourceDials.size()+1);
    _glay->addWidget(_CommonDial, 1, _sourceDials.size()+1);
    _glay->setColumnStretch(_sourceDials.size()+1, 0);
}

double SignalMixer::GetSample()
{
    std::vector<double> new_samples(_sources.size());
    for(unsigned int i = 0; i<_sources.size(); ++i)
        new_samples[i] = _sources[i]->GetSample();
    double summ = 0.0;
    for(unsigned int i = 0; i<new_samples.size(); ++i)
        summ+=new_samples[i]*_sourcesAmps[i];///TODO добавить коэффициенты усиления для каждого источника
    summ/=new_samples.size();///TODO добавить общий коэфф усиления на выходе
    return summ*_masterAmp;
}

void SignalMixer::ResetPosition()
{
    for(unsigned int i = 0; i<_sources.size(); ++i)
        _sources[i]->ResetPosition();
}

void SignalMixer::SetDiscretizationFrequency(int iDescrFreq)
{
    for(unsigned int i = 0; i<_sources.size(); ++i)
        _sources[i]->SetDiscretizationFrequency(iDescrFreq);
}
