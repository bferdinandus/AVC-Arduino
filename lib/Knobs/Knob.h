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

public:
    void begin(int pinA, int pinB, int index);

    void Update();

    int getValue();

    const String &getName() const;

    void setName(String newName);

    virtual ~Knob();

private:
    String name;
    Encoder *encoder;
    int position = 0;

    static Knob *instances[MAX_INSTANCES];

    static void isr0();

    static void isr1();

    static void isr2();
};

#endif //VOLUMECONTROLLER_KNOB_H
