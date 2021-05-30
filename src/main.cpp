#include "Arduino.h"
#include "Knobs.h"
#include "Display.h"
#include "Communication.h"

Knobs knobs;
Communication communication(&knobs);
Display display(&knobs);

void setup() {
    knobs.setup();
    communication.setup();
    display.setup();
}

void loop() {
    //knobs.loop();
    communication.loop();
    display.loop();
}