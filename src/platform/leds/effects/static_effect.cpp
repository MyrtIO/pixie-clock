#include "effects.h"

bool renderStaticEffect(CRGB* pixels, LEDState* state) {
  if (state->currentDigits == state->targetDigits &&
      state->currentColor == state->targetColor) {
    return false;
  }
  for (uint8_t i = 0; i < 4; i++) {
    pixels[state->currentDigits.matrixIndex(i)] = CRGB::Black;
    pixels[state->targetDigits.matrixIndex(i)] = state->targetColor;
  }
  state->currentDigits = state->targetDigits;
  state->currentColor = state->targetColor;
  return true;
}
