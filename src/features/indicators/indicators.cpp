#include "indicators.h"

uint8_t IndicatorsFeature::code() {
  return FeatureCode::Indicators;
}

void IndicatorsFeature::setup() {
  storage_->append(&stateDescriptor_);
  leds_->setDigitsColor(state_.color[0], state_.color[1], state_.color[2]);
  leds_->setBrightness(state_.brightness);
}

IndicatorsFeature::IndicatorsFeature() {}

// Function that runs as a background task.
void IndicatorsFeature::onTask() {
  // This feature should not have a primary task, so do nothing here.
}

// Handles action requests and performs actions based on the request.
bool IndicatorsFeature::onAction(IOActionRequest* request, IOFeatureController* controller) {
  switch (request->action) {
    case IndicatorsAction::SetColor:
      return handleSetColor_(request);
    case IndicatorsAction::SetBrightness:
      return handleSetBrightness_(request);
    case IndicatorsAction::GetColor:
      return handleGetColor_(request);
    case IndicatorsAction::GetBrightness:
      return handleGetBrightness_(request);
    case IndicatorsAction::SetPower:
      return handleSetPower_(request);
    case IndicatorsAction::GetPower:
      return handleGetPower_(request);
    case IndicatorsAction::SetEffect:
      return handleSetEffect_(request);
    case IndicatorsAction::GetEffect:
      return handleGetEffect_(request);
  }
  return false; // Unknown action
}

// Private method to handle setting LED color based on the request.
bool IndicatorsFeature::handleSetColor_(IOActionRequest* request) {
  if (request->length != 3) {
    return false; // Invalid payload length
  }
  leds_->setDigitsColor(request->payload[0], request->payload[1], request->payload[2]);
  copyColor(request->payload, state_.color);
  stateDescriptor_.update();
  return true;
}

// Private method to handle setting LED brightness based on the request.
bool IndicatorsFeature::handleSetBrightness_(IOActionRequest* request) {
  if (request->length != 1) {
    return false; // Invalid payload length
  }
  leds_->setBrightness(request->payload[0]);
  state_.brightness = request->payload[0];
  stateDescriptor_.update();
  return true; // Successfully set brightness
}

bool IndicatorsFeature::handleGetColor_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append(state_.color[0])
    ->append(state_.color[1])
    ->append(state_.color[2])
    ->flush();
  return true;
}

bool IndicatorsFeature::handleGetBrightness_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append(state_.brightness)
    ->flush();
  return true;
}

bool IndicatorsFeature::handleSetPower_(IOActionRequest* request) {
  if (request->length != 1 || request->payload[0] > 1) {
    return false;
  }
  leds_->setPower(request->payload[0]);
  return true;
}

bool IndicatorsFeature::handleGetPower_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append(leds_->getPower() ? 1 : 0)
    ->flush();
  return true;
}

bool IndicatorsFeature::handleGetEffect_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append(state_.effect)
    ->flush();
  return true;
}

bool IndicatorsFeature::handleSetEffect_(IOActionRequest* request) {
  if (request->length != 1) {
    return false;
  }
  leds_->setEffect(request->payload[0]);
  return true;
}
