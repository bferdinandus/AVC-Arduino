//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knob.h"


Knob::Knob(int pinA, int pinB) {
    pinMode(pinA, INPUT_PULLUP);
    pinMode(pinB, INPUT_PULLUP);

    encoder = new Encoder(pinA, pinB);
}

void Knob::UpdateValue() {
    oldPosition = newPosition;
    newPosition = encoder->read();
}

bool Knob::HasNewValue() {
    return oldPosition != newPosition;
}

int Knob::GetNewValue() {
    return newPosition;
}

