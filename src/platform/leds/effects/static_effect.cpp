#include "effects.h"

bool renderStaticEffect(CRGB* pixels, LEDState* state) {
  CRGB targetColor = state->finalTargetColor();
  if (state->currentDigits == state->targetDigits &&
      state->currentColor == targetColor) {
    return false;
  }
  for (uint8_t i = 0; i < 4; i++) {
    pixels[state->currentDigits.matrixIndex(i)] = CRGB::Black;
    pixels[state->targetDigits.matrixIndex(i)] = targetColor;
  }
  state->currentDigits = state->targetDigits;
  state->currentColor = targetColor;
  return true;
}
