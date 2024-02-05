#include "sleep.h"

void SleepListener::handle() {
  if (wait_.isDone()) {
    if (!sleeping_) {
      sleeping_ = true;
      lastValue_ = brightness_->current();
      brightness_->setBrightness(kSleepBrightness);
    }
  } else if (sleeping_) {
    brightness_->setBrightness(lastValue_);
    sleeping_ = false;
  }
}

void SleepListener::awake() {
  wait_.set(kSleepTimeout);
}

void SleepListener::start(SmoothBrightness* brightness) {
  brightness_ = brightness;
  awake();
}
