#include "Arduino.h"
#include "Knobs.h"
#include "Display.h"

Knobs knobs;
Display display;


void setup() {
    Serial.begin(115200);
    Serial.println("Setup");

    display.begin();
    display.showStartUp();
    delay(2000);
    display.clear();

    knobs.setup();
}

void loop() {

    // if computer connected then display knobs info
    display.showKnobsInfo(&knobs);

    // todo: wait for connection from computer


    // todo: show receiving data
}