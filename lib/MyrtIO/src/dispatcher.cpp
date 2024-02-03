#include "dispatcher.h"

IODevice* IODispatcher::setup() {
  device_ = new IODevice();
  return device_;
}

void IODispatcher::onRequest(IORequest* request) {
  uint8_t* payload = request->payload();
  uint8_t length = request->length();
  if (length < 2) {
    return;
  }
  for (uint8_t i = 0; i < device_->featuresCount; i++) {
    // Serial.write(device_->featureList[i]->code);
    if (device_->featureList[i]->code() == payload[0]) {
      runAction_(request, device_->featureList[i]);
      return;
    }
  }
}

void IODispatcher::handle() {
  for (uint8_t i = 0; i < device_->platformsCount; i++) {
    device_->platformList[i]->onLoopStart();
  }

  if (active_ == nullptr) {
    device_->idleFeature->onTask();
  } else {
    active_->onTask();
  }

  for (uint8_t i = 0; i < device_->platformsCount; i++) {
    device_->platformList[i]->onLoopEnd();
  }
}

void IODispatcher::setActive(uint8_t code) {
  for (uint8_t i = 0; i < device_->featuresCount; i++) {
    if (device_->featureList[i]->code() == code) {
      active_ = device_->featureList[i];
      return;
    }
  }
}

void IODispatcher::unsetActive() {
  active_ = nullptr;
}

 void IODispatcher::runAction_(IORequest* request, IOFeature* target) {
  IOActionRequest* action = new IOActionRequest(request);
  bool success = target->onAction(action, this);
  if (!action->sent()) {
    action->replyStatus(success);
  }
  delete action;
}
