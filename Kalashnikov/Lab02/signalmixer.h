#ifndef SIGNALMIXER_H

#define SIGNALMIXER_H

#include "signalgenerator.h"

class SignalMixer : public SignalGenerator
{ /// Микшер
public:
    SignalMixer();
    ~SignalMixer();
};

#endif // SIGNALMIXER_H
