#include "Arduino.h"
#include "Knobs.h"
#include "Display.h"

Knobs knobs = Knobs();
Display display = Display();


void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.println("Setup");

	display.begin();
	display.showStartUp();
	delay(2000);
	display.clear();
}

void loop() {

    // if computer connected then display knobs info
	display.showKnobsInfo(&knobs);

    // todo: wait for connection from computer


    // todo: show receiving data
}