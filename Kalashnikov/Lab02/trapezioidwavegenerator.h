#ifndef TRAPEZIOIDWAVEGENERATOR_H
#define TRAPEZIOIDWAVEGENERATOR_H

class trapezioidwavegenerator : public signalgenerator
{ // трапецеидальный сигнал
public:
    trapezioidwavegenerator();
    void SetRizePeriod(double iRizePeriod); // Метод/функция нарастания/фронта сигнала
    void SetFallPeriod(double iFallPeriod); // Метод/функция уменьшения/спада сигнала.
    ~trapezioidwavegenerator();
private:
};

#endif // TRAPEZIOIDWAVEGENERATOR_H
