#include "renderer.h"
#include "pixeltypes.h"

// Implementation of the setup function to initialize the LED matrix and set the rendering effect.
void LEDRenderer::setup(ILEDEffectRenderer render) {
  LEDS.addLeds<WS2812B, GPIO_PIN_LED_MATRIX, GRB>(digits_, kDigitsMatrixSize);
  LEDS.setCorrection(TypicalPixelString);
  setEffect(render);
}

// Implementation of the public method to handle a frame of animation and rendering.
bool LEDRenderer::handleFrame() {
  return render_(&digits_[0], &state_);
}

// Implementation of the public method to set the rendering effect for the LED matrix.
void LEDRenderer::setEffect(ILEDEffectRenderer render) {
  render_ = render;
}

// Implementation of the public method to set the digits to be displayed on the LED matrix.
void LEDRenderer::setDigits(uint8_t firstPair, uint8_t secondPair) {
  state_.targetDigits.set(firstPair, secondPair);
}

// Implementation of the public method to set the color for the LED matrix.
void LEDRenderer::setColor(uint8_t r, uint8_t g, uint8_t b) {
  state_.targetColor.r = r;
  state_.targetColor.g = g;
  state_.targetColor.b = b;
}
