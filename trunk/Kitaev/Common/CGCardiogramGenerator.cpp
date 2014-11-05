#include "CGCardiogramGenerator.h"

#include "math.h"

CardioGen::CardioGen(QObject *parent) :
    SignalGenerator(parent)
{
    ///установка начальной фазы сердцебиения
    _phase = phaseP;
    ///установка положения
    _pos = 0;
    ///установка частоты сердцебиения
    _heartRateBPM = 60;
    ///установка частоты дискретизации
    _discrFreq = 1000;

    ///установка длительности каждой фазы
    _lenP = 11;
    _lenPQ = 7;
    _lenQ = 1;
    _lenR = 5;
    _lenS = 2;
    _lenPostS = 1;
    _lenST = 9;
    _lenT = 14;
    _lenU = 9;


    _ampP = 3;
    _ampPQ = 0;
    _ampQ = 3;
    _ampR = 37;
    _ampS = 11;
    _ampPostS = 0;
    _ampST = 0;
    _ampT = 8;
    _ampU = 3;

    double ampK = 15.0/37.0;
    for(int i = 0; i<GetPhaseCount(); ++i)
        _phaseAmps[i]*=ampK;

    UpdateLengthTable();
}

void CardioGen::UpdateLengthTable()
{
    ///расчитываем таблицу длительностей
    double totalLength = 0;
    for(int i = 0; i<GetPhaseCount(); ++i)
        totalLength+=_phaseLengths[i];
    for(int i = 0; i<GetPhaseCount(); ++i)
    {
        _phaseStartPoints[i] = _discrFreq*_phaseLengths[i]/totalLength;
    }
}

void CardioGen::GenerateCH0(double *oSamples, int size)
{
    ///позиция в выходном массиве
    int outputPos = 0;
    while(outputPos<size)
    {
        double pos = _pos;
        switch(_phase)
        {
        case phaseP:
            oSamples[outputPos] = (1.0+cos(2.0*M_PI*(-0.5+pos/_phaseStartPoints[_phase])))*_phaseAmps[_phase]*0.5;
            break;
        case phasePQ:
            oSamples[outputPos] = 0;
            break;
        case phaseQ:
            oSamples[outputPos] = -pos/_phaseStartPoints[_phase]*_phaseAmps[_phase];
            break;
        case phaseR:
            oSamples[outputPos] = -_phaseAmps[phaseQ] + pos/_phaseStartPoints[_phase]*(_phaseAmps[phaseQ]+_phaseAmps[_phase]);
            break;
        case phaseS:
            oSamples[outputPos] = _phaseAmps[phaseR] - pos/_phaseStartPoints[_phase]*(_phaseAmps[phaseR]+_phaseAmps[_phase]);
            break;
        case phasePostS:
            oSamples[outputPos] = 0;
            break;
        case phaseST:
            oSamples[outputPos] = 0;
            break;
        case phaseT:
            oSamples[outputPos] = (1.0+cos(2.0*M_PI*(-0.5+pos/_phaseStartPoints[_phase])))*_phaseAmps[_phase]*0.5;
            break;
        case phaseU:
            oSamples[outputPos] = (1.0+cos(2.0*M_PI*(-0.5+pos/_phaseStartPoints[_phase])))*_phaseAmps[_phase]*0.5;
            break;
        }
        ++_pos;
        ++outputPos;
        if(_pos>=_phaseStartPoints[_phase])
        {
            _phase=(Phase)(_phase+1)%GetPhaseCount();
            _pos = 0;
        };
    }
}

SquareSignalGenerator::SquareSignalGenerator(QObject *parent):
    SignalGenerator(parent)
{
    ///установка начальной фазы сердцебиения
    _phase = phasePreImpulse;
    ///установка положения
    _pos = 0;
    ///установка частоты сердцебиения
    _heartRateBPM = 60;
    ///установка частоты дискретизации
    _discrFreq = 1000;

    ///установка длительности каждой фазы
    _lenPreImpulse = 0;
    _lenImpulse = 1;
    _lenPostImpulse = 1;

    _ampPreImpulse = 0;
    _ampImpulse = 10;
    _ampPostImpulse = 0;

    ///UpdateLengthTable();
    ///расчитываем таблицу длительностей
    double totalLength = 0;
    for(int i = 0; i<GetPhaseCount(); ++i)
        totalLength+=_phaseLengths[i];
    for(int i = 0; i<GetPhaseCount(); ++i)
    {
        _phaseStartPoints[i] = _discrFreq*_phaseLengths[i]/totalLength;
    }
}

void SquareSignalGenerator::GenerateCH0(double *oSamples, int size)
{
    ///позиция в выходном массиве
    int outputPos = 0;
    while(outputPos<size)
    {
        /*switch(_phase)
        {
        case phasePreImpulse:
            oSamples[outputPos] = _phaseAmps[_phase];
            break;
        case phaseImpulse:
            oSamples[outputPos] = _phaseAmps[_phase];
            break;
        case phasePostImpulse:
            oSamples[outputPos] = _phaseAmps[_phase];
            break;        }*/
        oSamples[outputPos] = _phaseAmps[_phase];
        ++_pos;
        ++outputPos;
        if(_pos>=_phaseStartPoints[_phase])
        {
            _phase=(Phase)(_phase+1)%GetPhaseCount();
            _pos = 0;
        };
    }
}
