#include <pins.h>
#include "leds.h"

void LEDPlatform::setup() {
  digits_.setup();
  // dot_.setup(GPIOPin::DotLED);
}

DigitsHandler* LEDPlatform::digits() {
  return &digits_;
}

void LEDPlatform::draw() {
  digits_.apply();
  FastLED.show();
}
