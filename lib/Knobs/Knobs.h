//
// Created by Ben Ferdinandus on 23-5-2021.
//

#ifndef VOLUMECONTROLLER_KNOBS_H
#define VOLUMECONTROLLER_KNOBS_H

#include "Arduino.h"
#include "LinkedList.h"
#include "Knob.h"

class Knobs {
private:
    long oldPosition = INT32_MIN;
    LinkedList<Knob *> list = LinkedList<Knob *>();

public:
    Knobs();

    void UpdateValues();

    bool HasNewValues();

    int GetValue(int knobNumber);

    int GetNumberOfKnobs();
};


#endif //VOLUMECONTROLLER_KNOBS_H
