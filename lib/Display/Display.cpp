//
// Created by Ben Ferdinandus on 29-5-2021.
//

#include <Knobs.h>
#include "Display.h"


Display::Display() {
    // init display
    //U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // graphic driver
    u8x8 = new U8X8_SSD1306_128X64_NONAME_HW_I2C(); //text driver
}

void Display::begin() {
    u8x8->begin();
    u8x8->setFont(u8x8_font_pcsenior_r);

    showStartUp();
    delay(2000);
    clear();
}

void Display::showStartUp() {
    u8x8->draw2x2String(3, 4, "A.V.C.");
}

void Display::updateKnobsInfo(Knobs *knobs) {

    if (!isTimeToUpdate()) {
        return;
    }

    const int maxCharacters = 16;
    char buf[maxCharacters];

    u8x8->drawString(0, 0, "VolumeController");

    for (int i = 0; i < knobs->GetNumberOfKnobs(); ++i) {
        snprintf(buf, maxCharacters, "Knob %d: %d      ", i, knobs->GetValue(i));
        u8x8->drawString(0, i + 2, buf);
    }
}

void Display::clear() {
    u8x8->clearDisplay();
}

void Display::drawString(uint8_t x, uint8_t y, const char *s) {
    u8x8->drawString(x, y, s);
}

bool Display::isTimeToUpdate() {
    if (t < millis()) {
        t = millis() + updateDelay;
        return true;
    }

    return false;
}