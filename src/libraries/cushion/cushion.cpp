#include "cushion.h"
#include "cushion_hardware.h"
#include <events.h>

const int oneSecondCount = 49911;

//TODO: replace toggleLED by explicit on, off commands

State::State(CushionHardware *hardware) {
  this->hardware = hardware;
}

Initial::Initial(CushionHardware *hardware) : State(hardware) {}

void Initial::enter() {
  hardware->sleep();
}

void Initial::exit() {
  // must be awake to have got here
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

Buzzing::Buzzing(CushionHardware *hardware) : State(hardware)  {}

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

Sitting::Sitting(CushionHardware *hardware) : State(hardware) {}

void Sitting::enter() {
    hardware->enableWDTimer();
    hardware->sleep();
    counter = 0;
}

void Sitting::exit() {
   hardware->disableWDTimer();
}


void Sitting::handleEvent(Event event, Cushion *context) {
  switch (event) {
    case GET_UP:
      context->initial();
      break;
    case WDT:
      counter++;
      if (counter > WAIT_25_MINS) {
        context->vibrating();
      }
      break;
    default:
      break;
  }
  return;
}

Vibrating::Vibrating(CushionHardware *hardware) : State(hardware) {}

void Vibrating::enter() {
    hardware->configureTimer1(SCALE1024);
    hardware->loadTimer1(oneSecondCount);
    hardware->enableTimer1();
    hardware->startVibrating();
}

void Vibrating::exit() {
    hardware->disableTimer1();
    hardware->stopVibrating();
}

void Vibrating::handleEvent(Event event, Cushion *context) {
  switch (event) {
    case TICK:
      context->waitingToStand();
      break;
    case GET_UP:
      context->initial();
      break;
    deafult:
      break;
  }
}

WaitingToStand::WaitingToStand(CushionHardware *hardware) : State(hardware) {}

void WaitingToStand::handleEvent(Event event, Cushion *context) {
switch (event) {
    case GET_UP:
      context->standing();
      break;
    default:
      break;
  }
}

Standing::Standing(CushionHardware *hardware) : State(hardware) {}

void Standing::enter() {
  hardware->enableWDTimer();
  hardware->sleep();
  counter = 0;
}

void Standing::exit() {
  hardware->disableWDTimer();
}

Cushion::Cushion(CushionHardware *hardware) { 
  _initial = new Initial(hardware);
  _buzzing = new Buzzing(hardware);
  _sitting = new Sitting(hardware);
  _vibrating = new Vibrating(hardware);
  _waitingToStand = new WaitingToStand(hardware);
  _standing = new Standing(hardware);
  _current = _initial;
  _current->enter();
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

void Cushion::vibrating() {
 nextState(_vibrating);
}

void Cushion::waitingToStand() {
 nextState(_waitingToStand);
}

void Cushion::standing() {
 nextState(_standing);
}

  
