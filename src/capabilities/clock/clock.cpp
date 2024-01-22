#include "clock.h"

ClockCapability::ClockCapability() {}

void ClockCapability::handlePrimary() {
  if (!nextFrame_.isDone() || !show_) {
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
  case ClockAction::SetColor:
    return handleSetColor_(request);
  case ClockAction::SetBrightness:
    return handleSetBrightness_(request);
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

bool ClockCapability::handleSetColor_(IOActionRequest* request) {
  if (request->length != 3) {
    return false;
  }
  CRGB targetColor;
  targetColor.r = request->payload[0];
  targetColor.g = request->payload[1];
  targetColor.b = request->payload[2];
  leds_->digits()->setColor(targetColor);
  leds_->draw();
  return true;
}

bool ClockCapability::handleSetBrightness_(IOActionRequest* request) {
  if (request->length != 1) {
    return false;
  }
  leds_->digits()->setBrightness(request->payload[0]);
  leds_->draw();
  return true;
}
