#include "cushion.h"
#include "cushion_hardware.h"
#include <events.h>

const int timer1count = 0;

Waiting::Waiting(CushionHardware *hardware) {
  this->hardware = hardware;
  hardware->configureTimer1(SCALE256);
  hardware->loadTimer1(timer1count); 
  hardware->enableTimer1();
  this->sitting = new Sitting(this);
}

State * Waiting::handleEvent(Event event) {
    switch (event) {
      case SIT_DOWN:
        return sitting;
      case TICK:
        hardware->toggleLed();
        hardware->loadTimer1(timer1count);
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


Cushion::Cushion(CushionHardware *hardware) { 
  current = new Waiting(hardware);
}

void Cushion::handleEvent(Event event) {
  current = current->handleEvent(event);
}

  
