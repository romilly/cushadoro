#include <cushion.h>
#include <cushion_hardware.h>
#include <events.h>
#include <avr/wdt.h>


ArduinoHardware *hardware= new ArduinoHardware;

EventBuffer eb = EventBuffer(4);
//ISR(WDT_vect) {
//  eb.post(WDT);
//}
ISR(TIMER1_OVF_vect)  {
  eb.post(TICK);
}

Cushion* cushion;


void setup() {
  Serial.begin(9600);
  Serial.println("starting");
  cushion = new Cushion(hardware);
  Serial.println("hardware set up");

}

void loop() {
  Event next;
  eb.dump();
  while(next = eb.next()) {
    Serial.print("handling event ");
    Serial.println(next);
    cushion->handleEvent(next);
  }
}
