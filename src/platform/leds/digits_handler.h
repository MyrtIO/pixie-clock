#pragma once

#include <FastLED.h>

// 4 segments with 10 digits
#define DIGITS_MATRIX_LED_COUNT 40

class DigitsHandler {
  public:
    void setup();
    void setDigits(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth);
    void setColor(CRGB first, CRGB second, CRGB third, CRGB fourth);
    void setColor(CRGB hours, CRGB minutes);
    void setColor(CRGB color);
    void setBrightness(uint8_t value);
    void apply();

  private:
    CRGB leds_[DIGITS_MATRIX_LED_COUNT];
    CRGB colors_[4] = {0, 0, 0, 0};
    uint8_t ledPositions_[4] = {255, 255, 255, 255};

    void clear_();
};
