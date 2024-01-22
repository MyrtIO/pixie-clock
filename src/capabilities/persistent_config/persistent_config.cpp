#include "persistent_config.h"

Config *PersistentConfigCapability::get() {
  return &config_;
}

void PersistentConfigCapability::write() {
  // descriptor_.update();
}
