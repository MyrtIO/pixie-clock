#include "effects.h"
#include <Timer.h>
#include "utils.h"

constexpr size_t kZoomFrameDuration = 350;

// TODO: add color support
bool renderZoomEffect(CRGB* pixels, LEDState* state) {
  CRGB targetColor = state->finalTargetColor();
  if (state->currentDigits == state->targetDigits &&
      state->currentColor == targetColor) {
    return false;
  }
  // Start animation
  if (!state->animating) {
    state->animating = true;
    effectProgress.start(kZoomFrameDuration);
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

  uint8_t* current = state->currentDigits.values();
  uint8_t* target = state->targetDigits.values();

  uint8_t steps;
  uint8_t currentValue;
  for (uint8_t i = 0; i < 4; i++) {
    if (target[i] == current[i]) {
      continue;
    }
    if (target[i] > current[i] || (target[i] == 0 && current[i] == 9)) {
      steps = current[i] + (10 - target[i]);
      currentValue = cyclicSubtract(current[i], map(progress, 0, 255, 0, steps));
    } else {
      steps = target[i] + (10 - current[i]);
      currentValue = (current[i] + map(progress, 0, 255, 0, steps)) % 10;
    }
    clearSegment(pixels, i);
    pixels[state->currentDigits.matrixIndexOf(currentValue, i)] = blend(state->currentColor, targetColor, progress);
  }
  return true;
}
