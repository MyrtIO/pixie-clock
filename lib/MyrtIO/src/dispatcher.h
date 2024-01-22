#pragma once

#include "request.h"
#include "device.h"

class IODispatcher : public IORequestListener {
  public:
    // Initializes the IODevice
    IODevice* init();

    // Handles incoming IORequest
    void onRequest(IORequest* request) override;

    // Primary handler for processing
    void handle();

    // Locks a specific IOCapability
    void lock(IOCapability *capability);

    // Unlocks the currently active IOCapability
    void unlock();

  private:
      IODevice* capabilities_ = nullptr;
      IOCapability* active_ = nullptr;

      void runAction_(IORequest* request, IOCapability* target);
};
