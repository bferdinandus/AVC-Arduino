//
// Created by Ben Ferdinandus on 30-5-2021.
//

#include "Communication.h"
#include "KnobData.h"

Communication::Communication() {}

void Communication::begin() {
    Serial.begin(115200);
    Serial.println("Setup");
}


void Communication::loop() {
    recvWithStartEndMarkers();
    if (newData) {
        strcpy(tempChars, receivedChars);
        // this temporary copy is necessary to protect the original data
        //   because strtok() used in parseData() replaces the commas with \0
        parseData();

        newData = false;
    }
}

void Communication::recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && !newData) {
        rc = Serial.read();

        if (recvInProgress) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            } else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        } else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void Communication::parseData() {      // split the data into its parts
    char *strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars, ",");      // get the first part - the string
    index = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(nullptr, ","); // this continues where the previous call left off
    strcpy(knobName, strtokIndx); // copy it to messageFromPC

    strtokIndx = strtok(nullptr, ",");
    percentage = atoi(strtokIndx);     // convert this part to a float

    parsedDataReady = true;
}

bool Communication::hasParsedData() const {
    return parsedDataReady;
}

KnobData Communication::getParsedData() {
    parsedDataReady = false;

    return KnobData{.name = knobName, .index = index, .percentage = percentage};
}