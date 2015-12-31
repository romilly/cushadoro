#include "cushion.h"
#include "cushion_hardware.h"
#include <events.h>

const int timer1count = 0;

// TODO: move hardware to State

Initial::Initial(CushionHardware *hardware) {
  this->hardware = hardware;
  this->sitting = new Sitting(this, hardware);
}

State * Initial::handleEvent(Event event) {
    switch (event) {
      case SIT_DOWN:
        sitting->enter();
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

Sitting::Sitting(State *initial, CushionHardware *hardware) {
  this->initial = initial;
  this->hardware = hardware;
}

void Sitting::enter() {
  hardware->configureTimer1(SCALE256);
  hardware->loadTimer1(timer1count);
  hardware->enableTimer1();
}


Cushion::Cushion(CushionHardware *hardware) { 
  current = new Initial(hardware);
}

void Cushion::handleEvent(Event event) {
  current = current->handleEvent(event);
}

  
