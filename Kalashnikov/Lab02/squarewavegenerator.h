#ifndef SQUAREWAVEGENERATOR_H
#define SQUAREWAVEGENERATOR_H
//генератора прямоугольного сигнала
class SquareWaveGenerator : public SignalGenerator
{
public:
    SquareWaveGenerator();
    void SetDutyCycle(double iDutyCycle); //метод задающий скважность
};

#endif // SQUAREWAVEGENERATOR_H
