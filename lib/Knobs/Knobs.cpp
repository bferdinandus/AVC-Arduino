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

bool Knobs::hasAnyKnobNewValue() {
    for (int i = 0; i < getNumberOfKnobs(); ++i) {
        if (list[i]) {
            return true;
        }
    }

    return false;
}

Knob *Knobs::getKnob(int32_t index) {
    return list[index];
}

Knob *Knobs::addKnob(const KnobData &data) {
    Knob *knob = list[data.index];
    if (knob == nullptr) {
        switch (data.index) {
            case 0:
                knob = new Knob(2, 3);
                break;
            case 1:
                knob = new Knob(4, 5);
                break;
            case 2:
                knob = new Knob(6, 7);
                break;
        }

        if (knob == nullptr) {
            // adding the knob failed
            Serial.println("Adding new knob failed (Knobs.cpp@addKnob()");
            return nullptr;
        }

        knob->begin();
        list[data.index] = knob;
    }

    knob->setName(data.name);
    knob->setValue(data.percentage);

    return knob;
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


