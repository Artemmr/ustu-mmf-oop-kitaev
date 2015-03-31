#include "rclowpassfilter.h"

RCLowPassFilter::RCLowPassFilter()
{
    _source = 0;///�������������� ��������� ����, ����� ��������, ��� �� ������
    _uout = 0;
    _discrFreq = 1000;
    _RC = 1.0/(2*3.14156265*35);//������ �� 35 ��
    UpdateAlfa();
}

double RCLowPassFilter::GetSample()
{
    if(_source==0)
        return 0.0;
    double sam = _source->GetSample();
    return _uout = sam*_alfa + _uout*(1.0-_alfa);
}

void RCLowPassFilter::SetFrequency(double iFrequency)
{
    if(_source==0)
        return;
    _source->SetFrequency(iFrequency);
}

void RCLowPassFilter::SetAmplitude(double iAmplitude)
{
    if(_source==0)
        return;
    _source->SetAmplitude(iAmplitude);
}

void RCLowPassFilter::SetOffset(double iOffset)
{
    if(_source==0)
        return;
    _source->SetOffset(iOffset);
}

void RCLowPassFilter::ResetPosition()
{
    if(_source==0)
        return;
    _uout = 0;
    _source->ResetPosition();
}

void RCLowPassFilter::SetDiscretizationFrequency(int iDescrFreq)
{
    if(_source==0)
        return;
    _discrFreq = iDescrFreq;
    _source->SetDiscretizationFrequency(iDescrFreq);
    UpdateAlfa();
}

bool RCLowPassFilter::SetSource(SignalGenerator *iSource)
{
    if(iSource==0)
        return false;
    _source = iSource;
    return true;
}

void RCLowPassFilter::SetRC(double iRC)
{
    _RC = iRC;
    UpdateAlfa();
}

///����� ��������� �������� _alfa
void RCLowPassFilter::UpdateAlfa()
{
    _alfa = 1.0/(_RC*_discrFreq+1.0);
}
