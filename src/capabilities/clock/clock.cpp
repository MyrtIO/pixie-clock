#include "clock.h"

ClockCapability::ClockCapability() {}

void ClockCapability::handlePrimary() {
  if (!nextFrame_.isDone()) {
    return;
  }
  uint8_t targetHour_ = rtc_->getHours();
  uint8_t targetMinute_ = rtc_->getMinutes();
  // Skip render if time is already set
  if (currentHour_ == targetHour_ && currentMinute_ == targetMinute_) {
    return;
  }
  leds_->digits()->setDigits(
    targetHour_ / 10, targetHour_ % 10,
    targetMinute_ / 10, targetMinute_ % 10
  );
  currentHour_ = targetHour_;
  currentMinute_ = targetMinute_;
  leds_->draw();
  nextFrame_.set(200);
}

void ClockCapability::handleBackground() {
  rtc_->read();
}

bool ClockCapability::handleAction(IOActionRequest* request) {
  switch (request->action) {
  case ClockAction::SetTime:
    return handleSetTime_(request);
  }
  return false;
}

void ClockCapability::setup() {
  // ¯\_(ツ)_/¯
  // Do nothing here
}

bool ClockCapability::handleSetTime_(IOActionRequest* request) {
  if (request->length != 3) {
    return false;
  }
  rtc_->setTime(request->payload[0], request->payload[1], request->payload[2]);
  return true;
}
