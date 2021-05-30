//
// Created by Ben Ferdinandus on 29-5-2021.
//

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdint-gcc.h>
#include <Knobs.h>
#include "U8x8lib.h"


class Display {
private:
    U8X8_SSD1306_128X64_NONAME_HW_I2C *u8x8;

    unsigned long t = 0;
    const int displayFps = 15;
    const int updateDelay = 1000 / displayFps;


public:
    Display();

    void showStartUp();

    void clear();

    void begin();

    void drawString(uint8_t x, uint8_t y, const char *s);

    void showKnobsInfo(Knobs *knobs);

    bool isTimeToUpdate();
};

#endif //_DISPLAY_H_
