#pragma once

#include <FastLED.h>
#include "../state.h"
#include <Timing.h>

constexpr uint8_t kDigitsMatrixSize = 40;

extern Progress effectProgress;

typedef bool (*ILEDEffectRenderer)(CRGB* pixels, LEDState* state);

bool renderStaticEffect(CRGB* pixels, LEDState* state);
bool renderSmoothEffect(CRGB* pixels, LEDState* state);
bool renderZoomEffect(CRGB* pixels, LEDState* state);
