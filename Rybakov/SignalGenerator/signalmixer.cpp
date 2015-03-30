#include "signalmixer.h"

#include <QLabel>
#include <QDial>
#include <QHBoxLayout>
#include <QVBoxLayout>

SignalMixer::SignalMixer(QWidget *iParent):
    QWidget(iParent)
{
    masterAmp = 1.0;

    QHBoxLayout *dials = new QHBoxLayout(this);

    QWidget *masterDialWidget;
    QLabel *masterLabel;
    dials->addWidget(masterDialWidget = new QWidget(this));
    {
        QWidget *parent = masterDialWidget;
        QVBoxLayout *dial = new QVBoxLayout(parent);
        dial->addWidget(masterLabel = new QLabel("Master",parent));
        dial->addWidget(masterDial = new QDial(this));
        masterLabel->setAlignment(Qt::AlignCenter);
    }
    connect(masterDial, SIGNAL(valueChanged(int)), this, SLOT(DialValueChange(int)));
}

void SignalMixer::DialValueChange(int)
{
    if(QObject::sender() == masterDial)
    {
        ///TODO изменить значение коэфф выходного усиления
        masterAmp = masterDial->value()/50.; //TODO 50 - цифра с потолка, переделать
    }
}

//Добавление источника
bool SignalMixer::AddSource(SignalGen *iSource)
{
    if(iSource == 0)
        return false;
    if(CheckSource(iSource))
        return false;
    sources.push_back(iSource);
    return true;
}

//Удалиние источника
bool SignalMixer::RemoveSource(SignalGen *iSource)
{
    if(!CheckSource(iSource))
        return false;
    std::vector<SignalGen*> new_sources;
    for(unsigned int i = 0; i<sources.size(); ++i)
        if(sources[i] != iSource)
            new_sources.push_back(sources[i]);
    sources = new_sources;
    return true;
}

bool SignalMixer::CheckSource(SignalGen *iSource)
{
    for(unsigned int i = 0; i<sources.size(); ++i)
        if(sources[i] == iSource)
            return true;
    return false;
}

double SignalMixer::GetSample()
{
    std::vector<double> new_samples(sources.size());
    for(unsigned int i = 0; i<sources.size(); ++i)
        new_samples[i] = sources[i]->GetSample();
    double summ = 0.0;
    for(unsigned int i = 0; i<new_samples.size(); ++i)
        summ+=new_samples[i];   //TODO добавить коэффициенты усиления для каждого источника
    summ/=new_samples.size();   //TODO добавить общий коэфф усиления на выходе
    return summ*masterAmp;
}

void SignalMixer::ResetPosition()
{
    for(unsigned int i = 0; i<sources.size(); ++i)
        sources[i]->ResetPosition();
}

void SignalMixer::SetDiscrFrequency(int iDescrFreq)
{
    for(unsigned int i = 0; i<sources.size(); ++i)
        sources[i]->SetDiscrFrequency(iDescrFreq);
}
