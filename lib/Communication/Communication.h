//
// Created by Ben Ferdinandus on 30-5-2021.
//

// I ised this source to come up with this class
// https://forum.arduino.cc/t/serial-input-basics-updated/382007/3
//

#ifndef VOLUMECONTROLLER_COMMUNICATION_H
#define VOLUMECONTROLLER_COMMUNICATION_H


#include <Arduino.h>
#include <KnobData.h>
#include <Knobs.h>

class Communication {
private:
    Knobs *knobs;
    bool newData = false;
    static const byte numChars = 32;
    char receivedChars[numChars] = {};
    char tempChars[numChars] = {};        // temporary array for use when parsing

    void recvWithStartEndMarkers();

    void parseData();

public:
    Communication(Knobs *pKnobs);

    void setup();

    void loop();

};


#endif //VOLUMECONTROLLER_COMMUNICATION_H
