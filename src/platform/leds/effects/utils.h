#pragma once

#include <FastLED.h>
#include "../clock_digits.h"

void clearAll(CRGB* pixels);
void clearSegment(CRGB* pixels, uint8_t index);
void forceApply(CRGB* pixels, ClockDigits* state, CRGB color);
uint8_t cyclicSubtract(uint8_t a, uint8_t b, uint8_t cycleBase = 10);
uint8_t cyclicAppend(uint8_t a, uint8_t b, uint8_t cycleBase = 10);
