#include <events.h>
#include <avr/wdt.h>
#include "cushion.h"

EventBuffer eb = EventBuffer(4);
ISR(WDT_vect) {
  eb.post(WDT);
}
ISR(TIMER1_OVF_vect)  {
  eb.post(TICK);
}

Cushion* cushion;


void setup() { 
  cushion = new Cushion;
}

void loop() {
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
  }
}
