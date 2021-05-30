#include "Arduino.h"
#include "Knobs.h"
#include "Display.h"
#include "Communication.h"

Knobs knobs;
Communication communication(&knobs);
Display display(&knobs);

// data to initialize the rotary knobs on the arduino
// send via serial port
// <index,name,volumePercentage)
// <1,FireFox,75>  <0,Master,35>  <2,Discord,100>

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