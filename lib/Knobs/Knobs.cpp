//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knobs.h"

Knobs::Knobs() {
    list.add(new Knob(2, 3));
    list.add(new Knob(4, 5));
    list.add(new Knob(6, 7));
}

void Knobs::UpdateValues() {
    for (int i = 0; i < list.size(); ++i) {
        list.get(i)->UpdateValue();
    }
}

int Knobs::GetValue(int knobNumber) {
    return list.get(knobNumber)->GetNewValue();
}

int Knobs::GetNumberOfKnobs() {
    return list.size();
}

bool Knobs::HasNewValues() {
    bool hasNewValues = false;
    for (int i = 0; i < list.size(); ++i) {
        hasNewValues = list.get(i)->HasNewValue() || hasNewValues;
    }

    return hasNewValues;
}
