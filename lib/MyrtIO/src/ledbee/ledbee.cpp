#include "ledbee.h"
#include <FastLED.h>

constexpr uint8_t kRendererFPS = 50;
constexpr uint8_t kFrameTime = 1000 / kRendererFPS;

LEDBee* LEDBee::init() {
  requestFrame_();
  return this;
}

LEDBee* LEDBee::brightness(IRenderer* render) {
  brightness_ = render;
  return this;
}

LEDBee* LEDBee::pixels(IRenderer* render) {
  pixels_ = render;
  return this;
}

void LEDBee::handle() {
  if (!shouldRenderFrame_()) {
    return;
  }
  bool hasChanges = false;
  hasChanges |= brightness_->handleFrame();
  hasChanges |= pixels_->handleFrame();
  if (hasChanges) {
    LEDS.show();
  }
  requestFrame_();
}

uint8_t LEDBee::fps() {
  return kRendererFPS;
}

void LEDBee::requestFrame_() {
  frame_.set(kFrameTime);
}

bool LEDBee::shouldRenderFrame_() {
  return frame_.isDone();
}
