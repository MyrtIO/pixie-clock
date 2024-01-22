#include "serial_provider.h"

#ifdef 

SerialRequestProvider::SerialRequestProvider(Stream* serial) {
  serial_ = serial;
}

void SerialRequestProvider::handle() {
  if (serial_->available() < IO_PROTOCOL_MESSAGE_META_LENGTH + 1) {
    return;
  }
  delay(SERIAL_PROVIDER_READ_DELAY);
  if (findHeader_() && readLength_() && readBody_()) {
    emitPayload_();
  }
}

bool SerialRequestProvider::readLength_() {
  int length = serial_->read();
  if (length <= 0 || length > IO_PROTOCOL_PAYLOAD_MAX_LENGTH) {
    return false;
  }
  message_[2] = (uint8_t)length;
  return true;
}

bool SerialRequestProvider::readBody_() {
  uint8_t payloadLength = message_[2];
  // Read body and tail
  int count = serial_->readBytes(&message_[3], payloadLength+1);
  if (count != message_[2]+1 || message_[payloadLength+3] != IOProtocolCode::TAIL) {
    return false;
  }
  return true;
}

bool SerialRequestProvider::findHeader_() {
  while(serial_->available() > 0) {
    message_[1] = serial_->read();
    if (message_[0] == IOProtocolCode::HEADER_FIRST &&
        message_[1] == IOProtocolCode::HEADER_SECOND) {
      message_[0] = 0;
      message_[1] = 0;
      return true;
    }
    message_[0] = message_[1];
  }
  return false;
}

void SerialRequestProvider::emitPayload_() {
  SerialRequest* request = new SerialRequest(&message_[3], message_[2], serial_);
  listener_->onRequest(request);
  delete request;
}
