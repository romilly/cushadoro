#include <cushion.h>
#include <cushion_hardware.h>
#include <events.h>
#include <avr/wdt.h>


ArduinoHardware *hardware= new ArduinoHardware;

EventBuffer eb = EventBuffer(4);
ISR(WDT_vect) {
  eb.post(WDT);
}
ISR(TIMER1_OVF_vect)  {
  eb.post(TICK);
}

Cushion* cushion;


void setup() {
  Serial.begin(9600);
  cushion = new Cushion(hardware);

}

void loop() {
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
  }
}
