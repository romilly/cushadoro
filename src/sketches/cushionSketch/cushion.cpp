#include "cushion.h"
#include "bsp.h"
#include <events.h>

const int timer1count = 0;

Waiting::Waiting(BSP *bsp) {
  this->bsp = bsp;
  bsp->configureTimer1(SCALE256);
  bsp->loadTimer1(timer1count); 
  bsp->enableTimer1();
  this->sitting = new Sitting(this);
}

State * Waiting::handleEvent(Event event) {
    switch (event) {
      case SIT_DOWN:
        return sitting;
      case TICK:
        bsp->toggleLed();
        bsp->loadTimer1(timer1count);
        return this;  
      case NON_EVENT:
        return this;
      default:
        return this;
    }
}

Sitting::Sitting(State *waiting) {
  this->waiting = waiting;
}


Cushion::Cushion(BSP *bsp) { 
  current = new Waiting(bsp);
}

void Cushion::handleEvent(Event event) {
  current = current->handleEvent(event);
}

  
