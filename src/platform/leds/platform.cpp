#include "platform.h"

// Implementation of the setup function to initialize the LED platform.
void LEDPlatform::setup() {
  sleep_.start(&brightness_);
  pixels_.setup(renderSmoothEffect);
  leds_.init()
    ->pixels(&pixels_)
    ->brightness(&brightness_);
}

// Implementation of the function called at the start of each loop iteration.
void LEDPlatform::onLoopStart() {
  sleep_.handle();
}

CRGB LEDPlatform::getColor() {
  return pixels_.state()->currentColor;
}

uint8_t LEDPlatform::brightness() {
  return brightness_.current();
}

// Implementation of the function called at the end of each loop iteration to handle LEDs.
void LEDPlatform::onLoopEnd() {
  leds_.handle();
}

// Implementation of the public method to set the digits to be displayed on the LEDs.
void LEDPlatform::setDigits(uint8_t firstPair, uint8_t secondPair) {
  pixels_.setDigits(firstPair, secondPair);
}

// Implementation of the public method to set the color for the LEDs.
void LEDPlatform::setDigitsColor(uint8_t r, uint8_t g, uint8_t b) {
  pixels_.setColor(r, g, b);
}

// Implementation of the public method to set the overall brightness of the LEDs.
void LEDPlatform::setBrightness(uint8_t brightness) {
  brightness_.setBrightness(brightness);
}

// Implementation of the public method to set power status of the LEDs.
void LEDPlatform::setPower(bool enabled) {
  pixels_.setPower(enabled);
}

bool LEDPlatform::getPower() {
  return pixels_.state()->enabled;
}

void LEDPlatform::handlePing() {
  sleep_.awake();
}
