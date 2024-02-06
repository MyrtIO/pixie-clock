#include "effects.h"
#include <Progress.h>
#include "utils.h"

constexpr size_t kSmoothTransitionDuration = 500;

bool renderSmoothEffect(CRGB* pixels, LEDState* state) {
  CRGB targetColor = state->finalTargetColor();

  bool sameColor = state->currentColor == targetColor;
  if (sameColor && state->currentDigits == state->targetDigits) {
    return false;
  }
  // Start animation
  if (!state->animating) {
    state->animating = true;
    effectProgress.start(kSmoothTransitionDuration);
  }
  uint8_t progress = effectProgress.get();
  // Handle finish
  if (progress == 255) {
    forceApply(pixels, &state->targetDigits, targetColor);
    state->currentDigits = state->targetDigits;
    state->currentColor = targetColor;
    state->animating = false;
    return true;
  }

  for (uint8_t i = 0; i < 4; i++) {
    if (sameColor && state->currentDigits.values_[i] == state->targetDigits.values_[i]) {
      continue;
    }
    if (progress < 128) {
      // Hide previous value on first half
      pixels[state->currentDigits.matrixIndex(i)] = blend(state->currentColor, CRGB::Black, progress * 2);
    } else {
      // Show target values on second half
      pixels[state->currentDigits.matrixIndex(i)] = CRGB::Black;
      pixels[state->targetDigits.matrixIndex(i)] = blend(CRGB::Black, targetColor, (progress - 128) * 2);
    }
  }
  return true;
}

