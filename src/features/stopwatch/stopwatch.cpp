#include "stopwatch.h"

StopwatchFeature::StopwatchFeature() {}

void StopwatchFeature::setup() {
  // Do nothing
}

uint8_t StopwatchFeature::code() {
  return FeatureCode::Stopwatch;
}

void StopwatchFeature::onTask() {
  if (startTime_ == 0) {
    startTime_ = rtc_->getUnixTime();
    return;
  }
  uint32_t diff = rtc_->getUnixTime() - startTime_;
  uint8_t minutes = diff / 60;
  uint8_t seconds = diff % 60;
  leds_->setDigits(minutes, seconds);
}

bool StopwatchFeature::onAction(IOActionRequest* request, IOFeatureController* controller) {
  switch (request->action) {
  case StopwatchAction::ActivateStopwatchFeature:
    startTime_ = 0;
    controller->setActive(code());
    return true;
  }
  return false;
}

