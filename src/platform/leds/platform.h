#pragma once

#include <MyrtIO.h>
#include <FastLED.h>
#include "interfaces/platform.h"
#include "brightness.h"
#include "renderer.h"

class LEDPlatform : public IOPlatform, public ILEDPlatform {
  public:
    // Setup function to initialize the LED platform.
    void setup();

    // Function called at the start of each loop iteration.
    void onLoopStart();

    // Function called at the end of each loop iteration to handle LEDs.
    void onLoopEnd();

    // Set the digits to be displayed on the LEDs.
    void setDigits(uint8_t firstPair, uint8_t secondPair);

    // Set the color for the LEDs.
    void setDigitsColor(uint8_t r, uint8_t g, uint8_t b);

    // Set the overall brightness of the LEDs.
    void setBrightness(uint8_t brightness);

  private:
    LEDBee leds_;
    SmoothBrightness brightness_;
    LEDRenderer pixels_;
};
