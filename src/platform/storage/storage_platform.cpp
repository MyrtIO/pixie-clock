#include "storage_platform.h"

void StoragePlatform::onLoopStart() {
  // Do nothing
}

void StoragePlatform::onLoopEnd() {
  storage_.handle();
}

void StoragePlatform::setup() {
  storage_.initialize();
}

bool StoragePlatform::append(Stored *value) {
  return storage_.append(value);
}
