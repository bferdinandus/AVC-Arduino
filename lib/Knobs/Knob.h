//
// Created by Ben Ferdinandus on 23-5-2021.
//

#ifndef VOLUMECONTROLLER_KNOB_H
#define VOLUMECONTROLLER_KNOB_H

#include "Encoder.h"

class Knob {
private:
    Encoder *encoder;
    long oldPosition = INT32_MIN;
    long newPosition = INT32_MIN;

public:
    Knob(int pinA, int pinB);

    void UpdateValue();

    bool HasNewValue();

    int GetNewValue();
};


#endif //VOLUMECONTROLLER_KNOB_H
