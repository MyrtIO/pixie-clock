#include "utils.h"

void clearSegment(CRGB* pixels, uint8_t index) {
  uint8_t offset = index * 10;
  for (uint8_t i = 0; i < 10; i++) {
    pixels[i + offset] = CRGB::Black;
  }
}

void clearAll(CRGB* pixels) {
  for (uint8_t i = 0; i < 4; i++) {
    clearSegment(pixels, i);
  }
}

void forceApply(CRGB* pixels, ClockDigits* digits, CRGB color) {
  clearAll(pixels);
  for (uint8_t i = 0; i < 4; i++) {
    pixels[digits->matrixIndex(i)] = color;
  }
}

uint8_t cyclicSubtract(uint8_t a, uint8_t b, uint8_t cycleBase = 10) {
  if (b > a) {
    return cycleBase - (b - a);
  } else {
    return a - b;
  }
}

uint8_t cyclicAppend(uint8_t a, uint8_t b, uint8_t cycleBase = 10) {
  if (a + b > cycleBase) {
    return (a + b) - cycleBase;
  } else {
    return a + b;
  }
}
