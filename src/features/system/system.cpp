#include "system.h"


SystemFeature::SystemFeature() {}

void SystemFeature::setup() {
  // Do nothing
}

uint8_t SystemFeature::code() {
  return FeatureCode::System;
}

void SystemFeature::onTask() {
  // Do nothing
}

bool SystemFeature::onAction(IOActionRequest* request, IOFeatureController* controller) {
  switch (request->action) {
  case SystemAction::Ping:
    leds_->handlePing();
    return true;
  case SystemAction::GetName:
    return handleGetName_(request);
  }
  return false;
}

bool SystemFeature::handleGetName_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append("PixieClock")
    ->flush();
  return true;
}
