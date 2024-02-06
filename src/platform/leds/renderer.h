#pragma once

#include <MyrtIO.h>
#include <FastLED.h>
#include "effects/effects.h"
#include "pins.h"

class LEDRenderer : public IRenderer {
  public:
    // Setup function to initialize the LED matrix and set the rendering effect.
    void setup(ILEDEffectRenderer render);

    // Public method to handle a frame of animation and rendering.
    // Returns true if rendering is needed.
    bool handleFrame();

    // Set the rendering effect for the LED matrix.
    void setEffect(ILEDEffectRenderer render);

    // Set the digits to be displayed on the LED matrix.
    void setDigits(uint8_t firstPair, uint8_t secondPair);

    // Set the color for the LED matrix.
    void setColor(uint8_t r, uint8_t g, uint8_t b);

    void setPower(bool state);

    LEDState* state();

  private:
    ILEDEffectRenderer render_ = nullptr;
    CRGB digits_[kDigitsMatrixSize];
    LEDState state_;
};
