#include "cushion.h"
#include "bsp.h"
#include <events.h>

BSP bsp;



void Waiting::handleEvent(Event event, Cushion* cushion) {
    switch (event) {
      case SIT_DOWN:
        cushion->sitDown();
        break;
      case TICK:
        bsp.toggleLed();
        bsp.loadTimer1(timer1count);   // load timer 1
        break;
      case NON_EVENT:
        break;
      default:
        break;
    }
}

Cushion::Cushion() {
  bsp.configureTimer1(SCALE256);
  bsp.loadTimer1(timer1count); 
  bsp.enableTimer1(); 
  waiting = new Waiting;
  sitting = new Sitting;
  current = waiting;
}


void Cushion::handleEvent(Event event) {
  current->handleEvent(event, this);
}

void Cushion::sitDown() {
  current = sitting;
}
  
