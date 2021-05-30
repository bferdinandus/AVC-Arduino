//
// Created by Ben Ferdinandus on 23-5-2021.
//

#ifndef VOLUMECONTROLLER_KNOBS_H
#define VOLUMECONTROLLER_KNOBS_H

#include "Arduino.h"
#include "LinkedList.h"
#include "Knob.h"

class Knobs
{
 private:
	LinkedList<Knob*> list = LinkedList<Knob*>();

 public:
	Knobs();

	void setup();

	int GetNumberOfKnobs();

	int GetValue(int32_t num);
};

#endif //VOLUMECONTROLLER_KNOBS_H
