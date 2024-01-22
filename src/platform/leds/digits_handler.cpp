#include "digits_handler.h"
#include <pins.h>

void DigitsHandler::setup() {
  FastLED.addLeds<WS2812B, GPIO_PIN_LED_MATRIX, GRB>(leds_, DIGITS_MATRIX_LED_COUNT);
  setColor(CRGB::White);
}

void DigitsHandler::setDigits(uint8_t first, uint8_t second, uint8_t third, uint8_t fourth) {
  clear_();
  ledPositions_[0] = first;
  ledPositions_[1] = second + 10;
  ledPositions_[2] = third + 20;
  ledPositions_[3] = fourth + 30;
}

void DigitsHandler::setColor(CRGB first, CRGB second, CRGB third, CRGB fourth) {
  colors_[0] = first;
  colors_[1] = second;
  colors_[2] = third;
  colors_[3] = fourth;
}

void DigitsHandler::setColor(CRGB hours, CRGB minutes) {
  setColor(hours, hours, minutes, minutes);
}

void DigitsHandler::setColor(CRGB color) {
  setColor(color, color, color, color);
}

void DigitsHandler::setBrightness(uint8_t value) {
  FastLED.setBrightness(value);
}

void DigitsHandler::apply() {
  for (uint8_t i = 0; i < 4; i++) {
    leds_[ledPositions_[i]] = colors_[i];
  }
}

void DigitsHandler::clear_() {
  for (uint8_t i = 0; i < 4; i++) {
    leds_[ledPositions_[i]] = CRGB::Black;
  }
}
