#ifndef CGCARDIOGRAMGENERATOR_H
#define CGCARDIOGRAMGENERATOR_H

#include <QObject>
#include <QString>

#include <vector>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QObject *parent = 0):QObject(parent){}

    ///Метод возвращает количество регулируемых отрезков сигнала (фаз сердечного ритма или др.)
    virtual int GetPhaseCount() = 0;

    typedef int Phase;
    ///простое преобразование типов
    static Phase phaseNum(int iNum) {return (Phase)iNum;}
    ///Метод возвращает название соответствующего отрезка
    virtual QString phaseName(Phase iPhaseNum) = 0;
    ///Метод возвращает номер сэмпла, с которого начинается соответствующая фаза
    virtual int PhaseStart(Phase iPhase) = 0;

    ///возвращает длину фазы
    virtual double GetPhaseLength(Phase iPhase) = 0;
    virtual void SetPhaseLength(Phase iPhase, double iLength) = 0;

    ///возвращает амплитуду фазы
    virtual double GetPhaseAmplitude(Phase iPhase) = 0;
    virtual void SetPhaseAmplitude(Phase iPhase, double iLength) = 0;

    virtual int GetDiscrFreq(){return _discrFreq;}
    virtual void SetDiscrFreq(int iFreq){_discrFreq = iFreq;}

    virtual int GetHeartBPM(){return _heartRateBPM;}
    virtual void SetHeartBPM(int iHeartBPM){_heartRateBPM = iHeartBPM;}

    virtual int GetSamplesPerPeriod() {return (60*_discrFreq)/_heartRateBPM;}

    void ResetPosition(){_pos = 0; _phase=0;}

    ///Генерация сигнала для канала 0
    virtual void GenerateCH0(double *oSamples, int size) = 0;

protected:
    ///частота сердцебиений
    int _heartRateBPM;
    ///частота дискретизации, Гц
    int _discrFreq;
    ///текущая фаза сердцебиения
    Phase _phase;
    ///текущее позиция в фазе
    int _pos;

};

class CardioGen : public SignalGenerator
{
    Q_OBJECT
private:
    static const int _phaseCount = 9;
public:
    ///количество фаз сердечного ритма
    virtual int GetPhaseCount(){return _phaseCount;}

    ///Фазы сердечного ритма
    static const Phase
    phaseP = 0,
    phasePQ = 1,
    phaseQ = 2,
    phaseR = 3,
    phaseS = 4,
    phasePostS = 5,
    phaseST = 6,
    phaseT = 7,
    phaseU = 8;

    virtual QString phaseName(Phase iPhaseNum)
    {
        switch(iPhaseNum)
        {
        case phaseP:
            return QString(tr("P"));
        case phasePQ:
            return QString(tr("PQ"));
        case phaseQ:
            return QString(tr("Q"));
        case phaseR:
            return QString(tr("R"));
        case phaseS:
            return QString(tr("S"));
        case phasePostS:
            return QString(tr("PostS"));
        case phaseST:
            return QString(tr("ST"));
        case phaseT:
            return QString(tr("T"));
        case phaseU:
            return QString(tr("U"));
        default:
            return QString(tr("No such phase"));
        }
    }

private:
    ///продолжительность фаз сердечного ритма в безразмерных величинах
    union
    {
        double _phaseLengths[_phaseCount];
        struct
        {
            double
            _lenP,
            _lenPQ,
            _lenQ,
            _lenR,
            _lenS,
            _lenPostS,
            _lenST,
            _lenT,
            _lenU;
        };
    };
    ///Номера сэмплов, с которых начинается та или иная фаза
    double _phaseStartPoints[_phaseCount];

public:
    ///возвращает длину фазы
    virtual double GetPhaseLength(Phase iPhase){return _phaseLengths[iPhase];}
    virtual void SetPhaseLength(Phase iPhase, double iLength){_phaseLengths[iPhase] = iLength;}
    ///возвращает номер сэмпла в периоде, в котором начинается фаза сердечного ритма
    virtual int PhaseStart(Phase iPhase){return _phaseStartPoints[iPhase];}

private:
    ///амплитуда сигналов соответствубщих фаз
    union
    {
        double _phaseAmps[_phaseCount];
        struct
        {
            double
            _ampP,
            _ampPQ,
            _ampQ,
            _ampR,
            _ampS,
            _ampPostS,
            _ampST,
            _ampT,
            _ampU;
        };
    };
public:
    ///возвращает длину фазы
    virtual double GetPhaseAmplitude(Phase iPhase){return _phaseAmps[iPhase];}
    virtual void SetPhaseAmplitude(Phase iPhase, double iLength){_phaseAmps[iPhase] = iLength;}

    explicit CardioGen(QObject *parent = 0);

    ///обновление таблицы
    void UpdateLengthTable();

    ///Генерация сигнала для канала 1
    virtual void GenerateCH0(double *oSamples, int size);

private:

    ///флаг о добавлении к сигналу ВЧ шума со среднеувадратичным значением напряжения 25 мкВ (по ГОСТ 60601-2-51-2011) ///TODO
    bool _addHFnoize;
    ///флаг о добавлении к сигналу сетевой синусоидальной помехи с амплитудой 25 мкВ и частотой 50 Гц(по ГОСТ 60601-2-51-2011) ///TODO
    bool _add50Hznoize;
    ///флаг о добавлении к сигналу НЧ колебаний базовой линии с амплитудой 0,5 мВ и частотой 0,3 Гц (по ГОСТ 60601-2-51-2011) ///TODO
    bool _addLFnoize;
};

class SquareSignalGenerator : public SignalGenerator
{
    Q_OBJECT
public:
private:
    static const int _phaseCount = 3;
public:
    ///количество фаз сердечного ритма
    virtual int GetPhaseCount(){return _phaseCount;}

    ///Фазы сердечного ритма
    static const Phase
    phasePreImpulse = 0,
    phaseImpulse = 1,
    phasePostImpulse = 2;

    virtual QString phaseName(Phase iPhaseNum)
    {
        switch(iPhaseNum)
        {
        case phasePreImpulse:
            return QString(tr("PreImpulse"));
        case phaseImpulse:
            return QString(tr("Impulse"));
        case phasePostImpulse:
            return QString(tr("PostImpulse"));
        default:
            return QString(tr("No such phase"));
        }
    }

private:
    ///продолжительность фаз сердечного ритма в безразмерных величинах
    union
    {
        double _phaseLengths[_phaseCount];
        struct
        {
            double
            _lenPreImpulse,
            _lenImpulse,
            _lenPostImpulse;
        };
    };
    ///Номера сэмплов, с которых начинается та или иная фаза
    double _phaseStartPoints[_phaseCount];

public:
    ///возвращает длину фазы
    virtual double GetPhaseLength(Phase iPhase){return _phaseLengths[iPhase];}
    virtual void SetPhaseLength(Phase iPhase, double iLength){_phaseLengths[iPhase] = iLength;}
    ///возвращает номер сэмпла в периоде, в котором начинается фаза сердечного ритма
    virtual int PhaseStart(Phase iPhase){return _phaseStartPoints[iPhase];}

private:
    ///амплитуда сигналов соответствубщих фаз
    union
    {
        double _phaseAmps[_phaseCount];
        struct
        {
            double
            _ampPreImpulse,
            _ampImpulse,
            _ampPostImpulse;
        };
    };
public:
    ///возвращает длину фазы
    virtual double GetPhaseAmplitude(Phase iPhase){return _phaseAmps[iPhase];}
    virtual void SetPhaseAmplitude(Phase iPhase, double iLength){_phaseAmps[iPhase] = iLength;}

    explicit SquareSignalGenerator(QObject *parent = 0);

    virtual void GenerateCH0(double *oSamples, int size);
};


#endif // CGCARDIOGRAMGENERATOR_H
