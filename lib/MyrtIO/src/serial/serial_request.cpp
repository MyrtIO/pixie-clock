#include "serial_request.h"
#include <Arduino.h>

void SerialRequest::flushMessage(uint8_t* message, uint8_t messageLength) {
  serial_->write(message, messageLength);
  serial_->flush();
}
