#include "signalmixer.h"

#include <QLabel>
#include <QDial>
#include <QHBoxLayout>
#include <QVBoxLayout>

SignalMixer::SignalMixer(QWidget *iParent):
    QWidget(iParent)
{
    _masterAmp = 1.0;

    QHBoxLayout *_hblay = new QHBoxLayout(this);

    QWidget *commmonDialWidget;
    _hblay->addWidget(commmonDialWidget = new QWidget(this));
    {
        QWidget *parent = commmonDialWidget;
        QVBoxLayout *vlay = new QVBoxLayout(parent);
        vlay->addWidget(new QLabel("Master", parent));
        vlay->addWidget(_CommonDial = new QDial(this));
    }
    connect(_CommonDial, SIGNAL(valueChanged(int)), this, SLOT(knobValueChanged(int)));
}

void SignalMixer::knobValueChanged(int value)
{
    if(QObject::sender()==_CommonDial)
    {
        ///TODO изменить значение коэфф выходного усиления
        _masterAmp = _CommonDial->value()/50.;///TODO 50 - цифра с потолка, переделать
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

double SignalMixer::GetSample()
{
    std::vector<double> new_samples(_sources.size());
    for(unsigned int i = 0; i<_sources.size(); ++i)
        new_samples[i] = _sources[i]->GetSample();
    double summ = 0.0;
    for(unsigned int i = 0; i<new_samples.size(); ++i)
        summ+=new_samples[i];///TODO добавить коэффициенты усиления для каждого источника
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
