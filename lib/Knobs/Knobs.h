//
// Created by Ben Ferdinandus on 23-5-2021.
//

#ifndef VOLUMECONTROLLER_KNOBS_H
#define VOLUMECONTROLLER_KNOBS_H

#include "Arduino.h"
#include "Knob.h"
#include <KnobData.h>

class Knobs
{
 private:
    Knob* list[3] = {};

 public:
    Knobs();

    void setup();

	int getNumberOfKnobs();

    Knob * addKnob(const KnobData& data);

	Knob * getKnob(int32_t index);

    bool hasAnyKnobNewValue();

    virtual ~Knobs();

};

#endif //VOLUMECONTROLLER_KNOBS_H
