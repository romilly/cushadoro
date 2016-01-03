#include "cushion.h"
#include "cushion_hardware.h"
#include <events.h>

const int oneSecondCount = 49911;

State::State(CushionHardware *hardware) {
  this->hardware = hardware;
}

Initial::Initial(CushionHardware *hardware) : State(hardware) {
}

void Initial::handleEvent(Event event, Cushion *context) {
    switch (event) {
      case SIT_DOWN:
        context->buzzing();
        break;
      default:
        break;
    }
    return;
}

Buzzing::Buzzing(CushionHardware *hardware) : State(hardware)  {
}

void Buzzing::enter() {
  hardware->configureTimer1(SCALE1024);
  hardware->loadTimer1(oneSecondCount);
  hardware->enableTimer1();
  hardware->toggleLed();
}

void Buzzing::exit() {
  hardware->disableTimer1();
  hardware->toggleLed();
}

void Buzzing::handleEvent(Event event, Cushion *context) {
  switch (event) {
    case GET_UP:
        context->initial();
        break;
     case TICK:
        context->sitting();
        break;
     default:
        break;
  }
  return;
}

Sitting::Sitting(CushionHardware *hardware) : State(hardware) {
}

void Sitting::enter() {
    hardware->enableWDTimer();
    hardware->sleep();
}

void Sitting::exit() {
   hardware->disableWDTimer();
}


void Sitting::handleEvent(Event event, Cushion *context) {
  switch (event) {
    case GET_UP:
      context->initial();
      break;
    default:
      break;
  }
  return;
}


Cushion::Cushion(CushionHardware *hardware) { 
  _initial = new Initial(hardware);
  _buzzing = new Buzzing(hardware);
  _sitting = new Sitting(hardware);
  _current = _initial;
}

void Cushion::handleEvent(Event event) {
  _current->handleEvent(event, this);
}

void Cushion::nextState(State * nextState) {
  _current->exit();
  _current = nextState;
  _current->enter();
}

void Cushion::initial() {
 nextState(_initial);
}

void Cushion::buzzing() {
 nextState(_buzzing);
}

void Cushion::sitting() {
 nextState(_sitting);
}
  
