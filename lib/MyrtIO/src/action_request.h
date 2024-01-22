#pragma once
#include "request.h"

enum IOActionsStatus : uint8_t {
  Success = 0xEE,
  Error = 0xFF
};

class IOActionRequest {
  public:
    uint8_t capability;
    uint8_t action;
    uint8_t* payload;
    uint8_t length;

    IOActionRequest(IORequest* request) {
      request_ = request;
      payload = request->payload();
      capability = payload[0];
      action = payload[1];
      length = request->length() - 2;
      // Move pointer
      if (length > 0) {
        payload = &payload[2];
      }
    }

    bool sent() {
      return sent_;
    }

    void replyStatus(bool success) {
      request_->response()
        ->append(capability)
        ->append(action)
        ->append(success ? IOActionsStatus::Success : IOActionsStatus::Error)
        ->flush();
    }

  private:
    IORequest* request_;
    bool sent_ = false;
};
