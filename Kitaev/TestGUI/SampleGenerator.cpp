#include "SampleGenerator.h"
#include <math.h>

SampleGenerator::SampleGenerator()
{
    _discrFreq = 1000;///Частота дискретизации по-умолчанию - 1000 Гц
    _frequency = 50.0;///Частота сигнала по-умолчанию - 50 Гц
    _phaseShift = 0.0;///Сдвиг фазы по-умолчанию - 0
    _amplitude = 1.0;

    _position = 0;///Начальный номер сэмпла - 0
}

//метод получения последующего сэмпла от генератора
double SampleGenerator::GetSample()
{
    //double t = _position*(1.0/((double)_discrFreq));
    //double result = cos(t*_frequency*2*M_PI + _phaseShift);
    double result = _amplitude*cos(_position*_frequency*2*M_PI/((double)_discrFreq) + _phaseShift);
    _position++;
    return result;
}

// метод задания частоты генерируемого сигнала
void SampleGenerator::SetFrequency(double iFrequency)
{
    _frequency = iFrequency;
}

// метод задания амплитуды генерируемого сигнала
void SampleGenerator::SetAmplitude(double iAmplitude)
{
    _amplitude = iAmplitude;
}

// метод задания сдвига фазы относительно начала отсчёта по времени
void SampleGenerator::SetOffset(double iOffset)
{
    _phaseShift = iOffset;
}

// метод сброса текущего времени
void SampleGenerator::ResetPosition()
{
    _position = 0;///Начальный номер сэмпла - 0
}

// метод задания частоты дискретизации сигнала
void SampleGenerator::SetDiscretizationFrequency(int iDiscrFreq)
{
    _discrFreq = iDiscrFreq;
}
