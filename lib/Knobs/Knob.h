//
// Created by Ben Ferdinandus on 23-5-2021.
//

#ifndef VOLUMECONTROLLER_KNOB_H
#define VOLUMECONTROLLER_KNOB_H

#define ENCODER_DO_NOT_USE_INTERRUPTS 1
#include "Encoder.h"

class Knob
{

 public:
	// Knob(int pinA, int pinB);

	void begin(int pinA, int pinB, int index);

	void switchPressed();

	int Value() const;

 private:
	int index;

	Encoder* encoder;

	static Knob* instances[3];

	static void switchPressedExt0()
	{
		if (Knob::instances[0] != nullptr)
		{
			Knob::instances[0]->switchPressed();
		}
	}  // end of Knob::switchPressedExt0

	static void switchPressedExt1()
	{
		if (Knob::instances[1] != nullptr)
		{
			Knob::instances[1]->switchPressed();
		}
	}  // end of Knob::switchPressedExt1

	static void switchPressedExt2()
	{
		if (Knob::instances[2] != nullptr)
		{
			Knob::instances[2]->switchPressed();
		}
	}  // end of Knob::switchPressedExt1



};

#endif //VOLUMECONTROLLER_KNOB_H
