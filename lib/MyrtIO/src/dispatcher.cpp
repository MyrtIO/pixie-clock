#include "dispatcher.h"

IODevice* IODispatcher::init() {
  capabilities_ = new IODevice();
  return capabilities_;
}

void IODispatcher::onRequest(IORequest* request) {
  uint8_t* payload = request->payload();
  uint8_t length = request->length();
  if (length < 2) {
    return;
  }
  for (uint8_t i = 0; i < capabilities_->count; i++) {
    if (capabilities_->list[i]->code == payload[0]) {
      runAction_(request, capabilities_->list[i]);
      return;
    }
  }
}

void IODispatcher::handle() {
  for (uint8_t i = 0; i < capabilities_->count; i++) {
      capabilities_->list[i]->handleBackground();
  }
  capabilities_->idle->handlePrimary();
}

void IODispatcher::lock(IOCapability *capability) {
  active_ = capability;
}

void IODispatcher::unlock() {
  active_ = nullptr;
}

 void IODispatcher::runAction_(IORequest* request, IOCapability* target) {
  IOActionRequest* action = new IOActionRequest(request);
  bool success = target->handleAction(action);
  if (!action->sent()) {
    action->replyStatus(success);
  }
  delete action;
}
