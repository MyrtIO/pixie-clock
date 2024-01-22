#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "neopixel.h"

class DotHandler {
  public:
    void setup(int16_t dot_pin);
    void setColor(uint32_t color);
    void setBrightness(uint8_t value);
    void draw();

  private:
    Adafruit_NeoPixel dot_;
    uint32_t color_ = 0;
};
