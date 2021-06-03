//
// Created by Ben Ferdinandus on 23-5-2021.
//

#include "Knob.h"
#include "EnableInterrupt.h"

Knob *Knob::instances[MAX_INSTANCES] = {};

void Knob::begin(int pinA, int pinB, int index) {
    encoder = new Encoder(pinA, pinB);

    switch (index) {
        case 0:
            enableInterrupt(pinA, isr0, CHANGE);
            enableInterrupt(pinB, isr0, CHANGE);
            instances[0] = this;
            break;
        case 1:
            enableInterrupt(pinA, isr1, CHANGE);
            enableInterrupt(pinB, isr1, CHANGE);
            instances[1] = this;
            break;
        case 2:
            enableInterrupt(pinA, isr2, CHANGE);
            enableInterrupt(pinB, isr2, CHANGE);
            instances[2] = this;
            break;
    }

    name = "Not Set";
}

void Knob::Update() {
    // read is also used to update the encoder state
    position = encoder->read();
//    if (value != oldValue) {
//        newValue = true;
//        oldValue = value;
//    }
}

bool Knob::hasNewValue() {
    return newValue;
}

const String &Knob::getName() const {
    return name;
}

void Knob::setName(const String newName) {
    Knob::name = newName;
}

int Knob::getValue(bool resetNewValueFlag) {
    if (resetNewValueFlag) {
        newValue = false;
    }

    value = position / 4;

    if (value < 0) {
        setValue(0);
    }

    if (value > 100) {
        setValue(100);
    }

//    if (value != oldValue) {
//        newValue = true;
//        oldValue = value;
//    }

    return value;
}

void Knob::setValue(int sValue) {
    if (sValue < 0) {
        sValue = 0;
    }

    if (sValue > 100) {
        sValue = 100;
    }

    value = sValue;
    position = sValue * 4;
    //encoder->write(position);
}

void Knob::isr0() {
    Knob::instances[0]->Update();
}

void Knob::isr1() {
    Knob::instances[1]->Update();
}

void Knob::isr2() {
    Knob::instances[2]->Update();
}

Knob::~Knob() {
    delete encoder;
    encoder = nullptr;
}
