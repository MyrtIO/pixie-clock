#include "effects.h"
#include <Progress.h>

constexpr size_t kSmoothTransitionDuration = 500;

Progress smoothProgress;

bool renderSmoothEffect(CRGB* pixels, LEDState* state) {
  if (state->currentDigits == state->targetDigits) {
    return false;
  }
  // Start animation
  if (!state->animating) {
    state->animating = true;
    smoothProgress.start(kSmoothTransitionDuration);
  }
  uint8_t progress = smoothProgress.get();
  // Handle finish
  if (progress == 255) {
    for (uint8_t i = 0; i < 4; i++) {
      pixels[state->currentDigits.matrixIndex(i)] = CRGB::Black;
      pixels[state->targetDigits.matrixIndex(i)] = state->targetColor;
    }
    state->currentDigits = state->targetDigits;
    state->animating = false;
  }

  for (uint8_t i = 0; i < 4; i++) {
    if (state->currentDigits.values_[i] == state->targetDigits.values_[i]) {
      continue;
    }
    if (progress < 128) {
      // Hide previous value on first half
      pixels[state->currentDigits.matrixIndex(i)] = blend(state->currentColor, CRGB::Black, progress * 2);
    } else {
      // Show target values on second half
      pixels[state->currentDigits.matrixIndex(i)] = CRGB::Black;
      pixels[state->targetDigits.matrixIndex(i)] = blend(CRGB::Black, state->currentColor, (progress - 128) * 2);
    }
  }
  return true;
}

