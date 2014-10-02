#ifndef TRAPEZIOIDWAVEGENERATOR_H
#define TRAPEZIOIDWAVEGENERATOR_H
//генератора трапецеидального сигнала
class TrapezioidWaveGenerator : public SignalGenerator
{
public:
    TrapezioidWaveGenerator();
    void SetRizePeriod(double iRizePeriod); // wtf?)
    void SetFallPeriod(double iFallPeriod);
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
