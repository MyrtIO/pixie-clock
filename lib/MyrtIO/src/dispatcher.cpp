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
  device_->idleFeature->onTask();
  for (uint8_t i = 0; i < device_->platformsCount; i++) {
    device_->platformList[i]->onLoopEnd();
  }
}

void IODispatcher::lock(IOFeature *capability) {
  active_ = capability;
}

void IODispatcher::unlock() {
  active_ = nullptr;
}

 void IODispatcher::runAction_(IORequest* request, IOFeature* target) {
  IOActionRequest* action = new IOActionRequest(request);
  bool success = target->onAction(action);
  if (!action->sent()) {
    action->replyStatus(success);
  }
  delete action;
}
