//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knob.h"
#include "EnableInterrupt.h"

// Class members
void Knob::begin(int pinA, int pinB, int index)
{
	this->index = index;
	encoder = new Encoder(pinA, pinB);



	switch (index)
	{
	case 0:
		enableInterrupt(pinA, switchPressedExt0, CHANGE);
		enableInterrupt(pinB, switchPressedExt0, CHANGE);
		instances[0] = this;
	case 1:
		enableInterrupt(pinA, switchPressedExt1, CHANGE);
		enableInterrupt(pinB, switchPressedExt1, CHANGE);
		instances[1] = this;
	case 2:
		enableInterrupt(pinA, switchPressedExt2, CHANGE);
		enableInterrupt(pinB, switchPressedExt2, CHANGE);
		instances[2] = this;
	}


}

void Knob::switchPressed()
{
	Serial.print("tick index! ");
	Serial.print(index);
	Serial.print(" ");
	Serial.println(encoder->read());
}

int Knob::Value() const
{
	return encoder->read();
}