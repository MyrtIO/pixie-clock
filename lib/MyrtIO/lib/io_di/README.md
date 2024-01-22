# IO_DI

Ultra-compact library for Dependency Injection. Allows to simplify singleton management in a small micro-controller project.

## Usage

### Provide

To provide the dependency, you need to create 2 files. In the `.cpp` file you create the entity to be provided, and in the `.h` file you represent that entity externally. Example:

#### platform.h

```cpp
#include <io_di.h>
#include "leds/leds.h"

ioProvideExtern(LEDPlatform);
```

#### platform.cpp
```cpp
#include "platform.h"

ioProvide(LEDPlatform);
```

### Inject

The `ioInject` macro is used for injection. It returns a pointer to an instance of the class.

```cpp
// clock.h
#include <io_di.h>
#include "leds/leds.h"

class ClockCapability {
  private:
    LEDPlatform* leds_ = ioInject(LEDPlatform):
}
```
