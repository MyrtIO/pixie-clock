#pragma once

#include <FastLED.h>

template<uint8_t ... Args>
class LEDBee {
  public:


    static void draw() {
      FastLED.show();
    }

  private:
    CRGB leds_[DIGITS_MATRIX_LED_COUNT];
};
