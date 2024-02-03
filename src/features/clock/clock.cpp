#include "clock.h"

ClockFeature::ClockFeature() {}

uint8_t ClockFeature::code() {
  return FeatureCode::Clock;
}

void ClockFeature::onTask() {
  uint8_t targetHour_ = rtc_->getHours();
  uint8_t targetMinute_ = rtc_->getMinutes();
  leds_->setDigits(targetHour_, targetMinute_);
}

bool ClockFeature::onAction(IOActionRequest* request, IOFeatureController* controller) {
  switch (request->action) {
  case ClockAction::SetTime:
    return handleSetTime_(request);
  case ClockAction::ActivateClockFeature:
    controller->setActive(code());
    return true;
  }
  return false;
}

bool ClockFeature::handleSetTime_(IOActionRequest* request) {
  if (request->length != 3) {
    return false;
  }
  rtc_->setTime(request->payload[0], request->payload[1], request->payload[2]);
  return true;
}
