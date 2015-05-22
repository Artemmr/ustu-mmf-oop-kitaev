#include "rclowpassfilter.h"

RCLOWPASSFILTER::RCLOWPASSFILTER()
{
    source = 0;
    uout = 0;
    DescrFreq = 1000;
    RC = 1.0/(2*3.14156265*35);
    UpdateAlpha();
}

double RCLOWPASSFILTER::GetSample()
{
    if(source==0)
        return 0.0;
    double sam = source->GetSample();
    return uout = sam*Alpha + uout*(1.0-Alpha);
}

RCLOWPASSFILTER::Result RCLOWPASSFILTER::SetFrequency(double iFrequency){
    if(source==0)
        return BadValue;
    source->SetFrequency(iFrequency);
    return Success;
}
void RCLOWPASSFILTER::SetAmplitude(double iAmplitude)
{
    if(source==0)
        return;
    source->SetAmplitude(iAmplitude);
}

RCLOWPASSFILTER::Result RCLOWPASSFILTER::SetOffset(double iOffset){
    if(source==0)
        return BadValue;
    source->SetOffset(iOffset);
    return Success;
}

void RCLOWPASSFILTER::ResetPosition()
{
    if(source==0)
        return;
    uout = 0;
    source->ResetPosition();
}

RCLOWPASSFILTER::Result RCLOWPASSFILTER::SetDiscretizationFrequency(int iDescrFreq)
{
    if(source==0)
        return BadValue;
    DescrFreq = iDescrFreq;
    source->SetDiscretizationFrequency(iDescrFreq);
    UpdateAlpha();
    return Success;
}

bool RCLOWPASSFILTER::SetSource(SignalGenerator *iSource)
{
    if(iSource==0)
        return false;
    source = iSource;
    return true;
}

void RCLOWPASSFILTER::SetRC(double iRC)
{
    RC = iRC;
    UpdateAlpha();
}

void RCLOWPASSFILTER::UpdateAlpha()
{
    Alpha = 1.0/(RC*DescrFreq+1.0);
}
