//
// Created by Ben Ferdinandus on 23-5-2021.

// I used these sources to get the static isr's use the state of the class
// * https://www.onetransistor.eu/2019/05/arduino-class-interrupts-and-callbacks.html
// * http://www.gammon.com.au/forum/?id=12983
//

#ifndef VOLUMECONTROLLER_KNOB_H
#define VOLUMECONTROLLER_KNOB_H

#define ENCODER_DO_NOT_USE_INTERRUPTS

#include <Arduino.h>
#include <Encoder.h>
#include <LinkedList.h>


class Knob {
    static LinkedList<Knob *> knobInstances;

    static void isr0();

    static void isr1();

    static void isr2();

public:
    Knob(int pinA, int pinB);

    void begin();

    void loop();

    int getValue(bool reset = false);

    void setValue(int value);

    const char *getName();

    void setName(String name);

    bool hasNewValue();

    void update();


private:
    int _pinA;
    int _pinB;
    volatile int _count = 0;
    volatile bool _hasNewValue = false;
    String _name;

    Encoder _encoder;

};

#endif //VOLUMECONTROLLER_KNOB_H
