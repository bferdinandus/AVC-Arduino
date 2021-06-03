//
// Created by Ben Ferdinandus on 23-5-2021.

// I used these sources to get the static isr's use the state of the class
// * https://www.onetransistor.eu/2019/05/arduino-class-interrupts-and-callbacks.html
// * http://www.gammon.com.au/forum/?id=12983
//

#ifndef VOLUMECONTROLLER_KNOB_H
#define VOLUMECONTROLLER_KNOB_H

#define ENCODER_DO_NOT_USE_INTERRUPTS

#include "Encoder.h"

#define MAX_INSTANCES 3

class Knob {

private:
    String name;
    Encoder *encoder;
    volatile int value = 0;
    volatile int position = 0;
    int oldValue = 0;
    bool newValue;

    static Knob *instances[MAX_INSTANCES];

    static void isr0();

    static void isr1();

    static void isr2();

public:
    void begin(int pinA, int pinB, int index);

    void Update();

    bool hasNewValue();

    int getValue(bool resetNewValueFlag = false);

    void setValue(int value);

    const String &getName() const;

    void setName(String newName);

    virtual ~Knob();
};

#endif //VOLUMECONTROLLER_KNOB_H
