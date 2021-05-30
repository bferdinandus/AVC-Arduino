#include "Arduino.h"
#include "Knobs.h"
#include "Display.h"
#include "Communication.h"

Knobs knobs;
Display display;
Communication communication;


void setup() {

    communication.begin();

    display.begin();

    knobs.begin();
}

void loop() {

    // if computer connected then display knobs info
    display.updateKnobsInfo(&knobs);

    // todo: wait for connection from computer
    communication.loop();
    if (communication.hasParsedData()) {
        //knobs.AddKnob(communication.getParsedData());
    }

    // todo: show receiving data
}