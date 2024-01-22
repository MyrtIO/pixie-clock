#include <MyrtIO.h>
#include <MyrtIO/serial_provider.h>
#include <platform.h>
#include <capabilities.h>

SerialRequestProvider serial(&Serial);
IODispatcher io;

void setup() {
  Serial.begin(9600);
  serial.setup();
  serial.setListener(&io);
  io.init()
    ->platform(
      ioInject(LEDPlatform),
      ioInject(RTCPlatform)
    )
    ->capabilities(
      ioInject(ClockCapability),
      ioInject(PersistentConfigCapability)
    )
    ->defaultCapability(
      ioInject(ClockCapability)
    );
}

void loop() {
  serial.handle();
  io.handle();
}
