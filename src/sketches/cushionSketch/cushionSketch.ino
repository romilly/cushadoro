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

Cushion* cushion = new Cushion;


void setup() { 
  bsp.configureTimer1(SCALE256);
  bsp.loadTimer1(timer1count); 
  bsp.enableTimer1(); 
}

void loop() {
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
  }
}
