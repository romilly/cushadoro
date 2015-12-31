#include <cushion.h>
#include <cushion_hardware.h>
#include <events.h>
#include <avr/wdt.h>


CushionHardware *hardware= new ArduinoHardware;

EventBuffer eb = EventBuffer(4);
ISR(WDT_vect) {
  eb.post(WDT);
}
ISR(TIMER1_OVF_vect)  {
  eb.post(TICK);
}

Cushion* cushion;


void setup() {
  cushion = new Cushion(hardware);

}

void loop() {
  while(eb.hasMore()) {
    cushion->handleEvent(eb.next());
  }
}
