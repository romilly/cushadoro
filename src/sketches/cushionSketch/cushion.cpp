#include "cushion.h"
#include "bsp.h"
#include <events.h>

const int timer1count = 0;

// State *waiting = new Waiting(bsp);

Waiting::Waiting(BSP *bsp) {
  this->bsp = bsp;
  bsp->configureTimer1(SCALE256);
  bsp->loadTimer1(timer1count); 
  bsp->enableTimer1(); 
}

void Waiting::handleEvent(Event event, Cushion* cushion) {
    switch (event) {
      case SIT_DOWN:
        cushion->sitDown();
        break;
      case TICK:
        bsp->toggleLed();
        bsp->loadTimer1(timer1count);   // load timer 1
        break;
      case NON_EVENT:
        break;
      default:
        break;
    }
}


Cushion::Cushion(BSP *bsp) { 
  waiting = new Waiting(bsp);
  sitting = new Sitting;
  current = waiting;
}


void Cushion::handleEvent(Event event) {
  current->handleEvent(event, this);
}

void Cushion::sitDown() {
  current = sitting;
}
  
