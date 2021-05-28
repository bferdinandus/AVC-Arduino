#include "Arduino.h"
#include "Knobs.h"
#include "U8x8lib.h"

Knobs knobs = Knobs();

// init display
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // graphic driver
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE); //text driver

void setup() {
    // write your initialization code here
    Serial.begin(115200);
    Serial.println("Setup");

    u8x8.begin();

    u8x8.setFont(u8x8_font_amstrad_cpc_extended_r);
    u8x8.drawString(0, 0, "Hello World!");
}

unsigned long t = 0;
int displayFps = 15;
unsigned long updateDelay = 1000 / displayFps;

char buf[30];
bool doUpdateOutput = false;

void loop() {
    // write your code here
/*    knobs.UpdateValues();
    if (knobs.HasNewValues()) {
        if (!doUpdateOutput) {
            //delay updating the display to be able to capture one click
            // of the rotary knob.
            // but only delay once
            t = millis() + 50;
        }

        doUpdateOutput = true;
    }
*/
    if (t < millis()) {
        t = millis() + updateDelay;
        doUpdateOutput = false;

        for (int i = 0; i < knobs.GetNumberOfKnobs(); ++i) {
            sprintf(buf, "Knob %d: %d      ", i, knobs.GetValue(i));
            u8x8.drawString(0, i + 1, buf);
            //Serial.print(buf);
        }
        //Serial.println();
    }
}