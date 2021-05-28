//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knobs.h"

Knobs::Knobs()
{
//    list.add(new Knob(2, 3));
//    list.add(new Knob(4, 5));
//    list.add(new Knob(6, 7));

	auto knob1 = new Knob();
	knob1->begin(2, 3, 0);
	list.add(knob1);

	auto knob2 = new Knob();
	knob2->begin(4, 5, 1);
	list.add(knob2);

	auto knob3 = new Knob();
	knob3->begin(6, 7, 2);
	list.add(knob3);

}

int Knobs::GetNumberOfKnobs()
{
	return list.size();
}

int Knobs::GetValue(int32_t num)
{
	return list.get(num)->GetValue();
}
