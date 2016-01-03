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
    State * buzzing = context->buzzing;
    switch (event) {
      case SIT_DOWN:
        context->nextState(buzzing);
      default:
        return;
    }
}

Buzzing::Buzzing(CushionHardware *hardware) : State(hardware)  {
}

void Buzzing::enter() {
  hardware->configureTimer1(SCALE1024);
  hardware->loadTimer1(oneSecondCount);
  hardware->enableTimer1();
  hardware->toggleLed();
}

void Buzzing::handleEvent(Event event, Cushion *context) {
  State * initial = context->initial;
  State * sitting = context->sitting;
  switch (event) {
    case GET_UP:
        context->nextState(initial);
     case TICK:
        context->nextState(sitting);
     default:
        return;
  }
}

void Buzzing::exit() {
  hardware->disableTimer1();
  hardware->toggleLed();
}

Sitting::Sitting(CushionHardware *hardware) : State(hardware) {
}

void Sitting::handleEvent(Event event, Cushion *context) {
  return;
}


Cushion::Cushion(CushionHardware *hardware) { 
  initial = new Initial(hardware);
  buzzing = new Buzzing(hardware);
  sitting = new Sitting(hardware);
  current = initial;
}

void Cushion::handleEvent(Event event) {
  current->handleEvent(event, this);
}

void Cushion::nextState(State * nextState) {
  current->exit();
  current = nextState;
  current->enter();
}

  
