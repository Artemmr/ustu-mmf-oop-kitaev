#include "rclowpassfilter.h"

RCLowPassFilter::RCLowPassFilter()
{
    source = 0;
    uout = 0;
    DiscrFreq = 1000;
    RC = 1.0/(2*3.14156265*35);
    UpdateAlpha();
}

double RCLowPassFilter::GetSample()
{
    if(source==0)
        return 0.0;
    double sam = source->GetSample();
    return uout = sam*Alpha + uout*(1.0-Alpha);
}

void RCLowPassFilter::SetFrequency(double iFrequency)
{
    if(source==0)
        return;
    source->SetFrequency(iFrequency);
}
void RCLowPassFilter::SetAmplitude(double iAmplitude)
{
    if(source==0)
        return;
    source->SetAmplitude(iAmplitude);
}

void RCLowPassFilter::SetOffset(double iOffset)
{
    if(source==0)
        return;
    source->SetOffset(iOffset);
}

void RCLowPassFilter::ResetPosition()
{
    if(source==0)
        return;
    uout = 0;
    source->ResetPosition();
}

void RCLowPassFilter::SetDiscrFrequency(int iDescrFreq)
{
    if(source==0)
        return;
    DiscrFreq = iDescrFreq;
    source->SetDiscrFrequency(iDescrFreq);
    UpdateAlpha();
}

bool RCLowPassFilter::SetSource(SignalGen *iSource)
{
    if(iSource==0)
        return false;
    source = iSource;
    return true;
}

void RCLowPassFilter::SetRC(double iRC)
{
    RC = iRC;
    UpdateAlpha();
}

///����� ��������� �������� _alfa
void RCLowPassFilter::UpdateAlpha()
{
    Alpha = 1.0/(RC*DiscrFreq+1.0);
}
