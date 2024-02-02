#pragma once

#include "request.h"
#include "device.h"

class IODispatcher : public IORequestListener {
  public:
    // Initializes the IODevice
    IODevice* setup();

    // Handles incoming IORequest
    void onRequest(IORequest* request) override;

    // Primary handler for processing
    void handle();

    // Locks a specific IOFeature
    void lock(IOFeature *capability);

    // Unlocks the currently active IOFeature
    void unlock();

  private:
      IODevice* device_ = nullptr;
      IOFeature* active_ = nullptr;

      void runAction_(IORequest* request, IOFeature* target);
};
