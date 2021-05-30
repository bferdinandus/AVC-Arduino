//
// Created by Ben Ferdinandus on 30-5-2021.
//

#ifndef VOLUMECONTROLLER_COMMUNICATION_H
#define VOLUMECONTROLLER_COMMUNICATION_H


#include <Arduino.h>
#include <KnobData.h>
#include <Knobs.h>

class Communication {
private:
    bool newData = false;

    static const byte numChars = 32;
    char receivedChars[numChars] = {};
    char tempChars[numChars] = {};        // temporary array for use when parsing

    Knobs *knobs;

    void recvWithStartEndMarkers();

    void parseData();

public:
    Communication(Knobs *pKnobs);

    void setup();

    void loop();


    bool hasParsedData() const;

    KnobData getParsedData();
};


#endif //VOLUMECONTROLLER_COMMUNICATION_H
