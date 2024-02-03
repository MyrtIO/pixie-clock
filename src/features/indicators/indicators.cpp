#include "indicators.h"

uint8_t IndicatorsFeature::code() {
  return FeatureCode::Indicators;
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
      return handleGetColor_(request);
  }
  return false; // Unknown action, return false
}

// Private method to handle setting LED color based on the request.
bool IndicatorsFeature::handleSetColor_(IOActionRequest* request) {
  if (request->length != 3) {
    return false; // Invalid payload length, return false
  }
  leds_->setDigitsColor(request->payload[0], request->payload[1], request->payload[2]);
  return true; // Successfully set color
}

// Private method to handle setting LED brightness based on the request.
bool IndicatorsFeature::handleSetBrightness_(IOActionRequest* request) {
  if (request->length != 1) {
    return false; // Invalid payload length, return false
  }
  leds_->setBrightness(request->payload[0]);
  return true; // Successfully set brightness
}

bool IndicatorsFeature::handleGetColor_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  CRGB color = leds_->getColor();
  request
    ->startReply(true)
    ->append(color.r)
    ->append(color.g)
    ->append(color.b)
    ->flush();
  return true;
}

bool IndicatorsFeature::handleGetBrightness_(IOActionRequest* request) {
  if (request->length != 0) {
    return false;
  }
  request
    ->startReply(true)
    ->append(leds_->brightness())
    ->flush();
  return true;
}
