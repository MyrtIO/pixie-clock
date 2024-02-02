#include "platform.h"

// Implementation of the setup function to initialize the LED platform.
void LEDPlatform::setup() {
  pixels_.setup(renderSmoothEffect);
  leds_.init()
    ->pixels(&pixels_)
    ->brightness(&brightness_);
}

// Implementation of the function called at the start of each loop iteration.
void LEDPlatform::onLoopStart() {
  // Do nothing
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