//
// Created by Ben Ferdinandus on 5-6-2021.
//

#include "Knob.h"
#include <EnableInterrupt.h>

Knob::Knob(int pinA, int pinB) : _pinA(pinA),
                                 _pinB(pinB),
                                 _encoder(pinA, pinB) {}

void Knob::begin() {
    switch (knobInstances.size()) {
        case 0:
            knobInstances.add(0, this);  // add current instance to `this` list (IMPORTANT!!!)
            enableInterrupt(_pinA, isr0, CHANGE);
            enableInterrupt(_pinB, isr0, CHANGE);
            break;
        case 1:
            knobInstances.add(1, this);  // add current instance to `this` list (IMPORTANT!!!)
            enableInterrupt(_pinA, isr1, CHANGE);
            enableInterrupt(_pinB, isr1, CHANGE);
            break;
        case 2:
            knobInstances.add(2, this);  // add current instance to `this` list (IMPORTANT!!!)
            enableInterrupt(_pinA, isr2, CHANGE);
            enableInterrupt(_pinB, isr2, CHANGE);
            break;
        default:
            Serial.println("Out of ISR functions for Knobs!");
    }
}

void Knob::loop() {}

int Knob::getValue(bool reset) {
    if (reset) {
        _hasNewValue = false;
    }

    return _count;
}

void Knob::setValue(int value) {
    _count = value;
    _encoder.write(value * 4);
}

const char *Knob::getName() {
    return _name.c_str();
}

void Knob::setName(String name) {
    _name = name;
}

bool Knob::hasNewValue() {
    return _hasNewValue;
}

void Knob::update() {
    int newCount = _encoder.read() / 4;
    if (newCount != _count) {
        _count = newCount;
        _hasNewValue = true;
    }
}


// Outside of class
LinkedList<Knob *> Knob::knobInstances = LinkedList<Knob *>();

void Knob::isr0() {
    if (Knob::knobInstances.get(0) != nullptr) {
        Knob::knobInstances.get(0)->update();
    }
}

void Knob::isr1() {
    if (Knob::knobInstances.get(1) != nullptr) {
        Knob::knobInstances.get(1)->update();
    }
}

void Knob::isr2() {
    if (Knob::knobInstances.get(2) != nullptr) {
        Knob::knobInstances.get(2)->update();
    }
}