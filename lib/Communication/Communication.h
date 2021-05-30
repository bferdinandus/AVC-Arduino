//
// Created by Ben Ferdinandus on 30-5-2021.
//

#ifndef VOLUMECONTROLLER_COMMUNICATION_H
#define VOLUMECONTROLLER_COMMUNICATION_H


#include <Arduino.h>
#include <KnobData.h>

class Communication {
private:
    bool newData;
    bool parsedDataReady;

    static const byte numChars = 32;
    char receivedChars[numChars];
    char tempChars[numChars];        // temporary array for use when parsing

    // variables to hold the parsed data
    char knobName[numChars] = {0};
    int index;
    int percentage;


    void recvWithStartEndMarkers();

    void parseData();

public:
    Communication();

    void begin();

    void loop();


    bool hasParsedData() const;

    KnobData getParsedData();
};


#endif //VOLUMECONTROLLER_COMMUNICATION_H
