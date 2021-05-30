//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knobs.h"

Knobs::Knobs() {}

void Knobs::setup() {
}

int Knobs::getNumberOfKnobs() {
    return sizeof list / sizeof list[0];
}

Knob *Knobs::getKnob(int32_t index) {
    return list[index];
}

void Knobs::addKnob(const KnobData &data) {
    Knob *knob = list[data.index];
    if (knob == nullptr) {
        knob = new Knob();

        switch (data.index) {
            case 0:
                knob->begin(2, 3, data.index);
                break;
            case 1:
                knob->begin(4, 5, data.index);
                break;
            case 2:
                knob->begin(6, 7, data.index);
                break;
        }

        list[data.index] = knob;
    }
    knob->setName(data.name);
}

Knobs::~Knobs() {
    for (int i = 0; i < getNumberOfKnobs(); ++i) {
        Knob *knob = list[i];
        if (knob != nullptr) {
            delete knob;
            list[i] = nullptr;
        }
    }
}


