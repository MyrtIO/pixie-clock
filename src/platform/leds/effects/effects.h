#pragma once

#include <FastLED.h>
#include "../state.h"

typedef bool (*ILEDEffectRenderer)(CRGB* pixels, LEDState* state);

bool renderStaticEffect(CRGB* pixels, LEDState* state);
bool renderSmoothEffect(CRGB* pixels, LEDState* state);
