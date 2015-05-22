#include <QLabel>
#include <QDial>
#include <QGridLayout>

#include "signalmixer.h"

SignalMixer::SignalMixer(QWidget *iParent):
    QWidget(iParent)
{
    masterAmp = 1.0;
    dialsCoeficient = 50.0;

    GridLay = new QGridLayout(this);
    masterLabel = new QLabel ("Master", this);
    masterDial = new QDial (this);
    masterLabel->setAlignment(Qt::AlignCenter);

    UpdateDials();
    connect(masterDial,SIGNAL(valueChanged(int)),this,SLOT(DialValueChanged(int)));
}

void SignalMixer::DialValueChanged(int){
    if (QObject::sender() == masterDial){
        masterAmp = masterDial->value()/50.;
        emit(UpdateOutput());
        return;
    }
    for (unsigned int i = 0; i<sourcesDials.size(); ++i){
        if (QObject::sender() == sourcesDials[i]){
            sourcesAmps[i]=sourcesDials[i]->value()/dialsCoeficient;
            emit(UpdateOutput());
            return;
        }
    }
}

void SignalMixer::UpdateDials(){
    GridLay->removeWidget(masterLabel);
    GridLay->removeWidget(masterDial);

    for(unsigned int i = 0; i<sourcesDials.size(); ++i)
        GridLay->removeWidget(sourcesDials[i]);
    for(unsigned int i = 0; i<sourcesLabels.size(); ++i)
        GridLay->removeWidget(sourcesLabels[i]);

    for(unsigned int i = 0; i<sourcesLabels.size(); ++i)
        GridLay->addWidget(sourcesLabels[i], 0, i);
    for(unsigned int i = 0; i<sourcesDials.size(); ++i)
        GridLay->addWidget(sourcesDials[i], 1, i);

    for(unsigned int i = 0; i<sourcesDials.size(); ++i)
        GridLay->setColumnStretch(i, 0);
    GridLay->setColumnStretch(sourcesDials.size(), 1);

    GridLay->addWidget(new QWidget(this), 0, sourcesDials.size());
    GridLay->addWidget(new QWidget(this), 1, sourcesDials.size());

    GridLay->addWidget(masterLabel, 0, sourcesDials.size()+1);
    GridLay->addWidget(masterDial, 1, sourcesDials.size()+1);
    GridLay->setColumnStretch(sourcesDials.size()+1, 0);
}

SignalGenerator::Result SignalMixer::AddSignalSource(SignalGenerator *iSource){
    if(iSource == 0)
        return BadValue;
//    if(ContainsSignalSource(iSource))
//        return BadValue;
    sources.push_back(iSource);
    sourcesAmps.push_back(1.0);
    sourcesLabels.push_back(new QLabel(sources.back()->GetName(),this));
    sourcesLabels.back()->setAlignment(Qt::AlignCenter);
    sourcesDials.push_back(new QDial(this));
    sourcesDials.back()->setValue(sourcesAmps.back()*dialsCoeficient);
    connect(sourcesDials.back(), SIGNAL(valueChanged(int)), this, SLOT(DialValueChanged(int)));
    UpdateDials();
    return Success;
}

SignalGenerator::Result SignalMixer::RemoveSignalSource(SignalGenerator *iSource){
//    if(!ContainsSignalSource(iSource))
//        return BadValue;
    std::vector<SignalGenerator*> new_sources;
    std::vector<double> new_sourcesAmps;
    std::vector<QLabel*> new_sourcesLabels;
    std::vector<QDial*> new_sourcesDials;
    for(unsigned int i = 0; i<sources.size(); ++i)
        if(sources[i] != iSource)
        {
            new_sources.push_back(sources[i]);
            new_sourcesAmps.push_back(sourcesAmps[i]);
            new_sourcesLabels.push_back(sourcesLabels[i]);
            new_sourcesDials.push_back(sourcesDials[i]);
        }
    sources = new_sources;
    sourcesAmps = new_sourcesAmps;
    sourcesLabels = new_sourcesLabels;
    sourcesDials = new_sourcesDials;
    UpdateDials();
    return Success;
}

double SignalMixer::GetSample(){
    std::vector<double> new_samples(sources.size());
    for(unsigned int i = 0; i < sources.size(); ++i)
        new_samples[i]=sources[i]->GetSample();
    double summ = 0.0;
    for(unsigned int i = 0; i <new_samples.size(); ++i)
        summ+=new_samples[i]*sourcesAmps[i];
    summ = summ/new_samples.size();
    return summ*masterAmp;
}

void SignalMixer::ResetPosition(){
    for(unsigned int i = 0; i < sources.size(); ++i)
        sources[i]->ResetPosition();
}

SignalMixer::Result SignalMixer::SetDiscretizationFrequency(int iDescrFreq){
    for(unsigned int i = 0; i<sources.size(); ++i)
        sources[i]->SetDiscretizationFrequency(iDescrFreq);
    return Success;
}

