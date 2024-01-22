#include <MyrtIO.h>
#include <MyrtIO/serial_provider.h>
#include <platform.h>
#include <capabilities.h>

SerialRequestProvider serialProvider(&Serial);
IODispatcher io;

void setup() {
  Serial.begin(9600);
  serialProvider.setup();
  serialProvider.setListener(&io);
  io.init()
    ->platform(
      IO_INJECT(LEDPlatform),
      IO_INJECT(RTCPlatform)
    )
    ->capabilities(
      IO_INJECT(ClockCapability),
      IO_INJECT(PersistentConfigCapability)
    )
    ->defaultCapability(
      IO_INJECT(ClockCapability)
    );
}

void loop() {
  serialProvider.handle();
  io.handle();
}
