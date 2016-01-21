#include "cushion.h"
#include "cushion_hardware.h"
#include <events.h>

const int oneSecondCount = 49911;

// TODO: see if I can find a common superclass for the two one-second timers

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

void Initial::handleEvent(Event event, Cushion *cushion) {
    switch (event) {
      case SIT_DOWN:
        cushion->buzzing();
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
  hardware->ledOn();
}

void Buzzing::exit() {
  hardware->disableTimer1();
  hardware->ledOff();
}

void Buzzing::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case GET_UP:
        cushion->initial();
        break;
     case TICK:
        cushion->sitting();
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


void Sitting::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case GET_UP:
      cushion->initial();
      break;
    case WDT:
      counter++;
      if (counter > WAIT_25_MINS) {
        cushion->vibrating();
      }
      break;
    default:
      break;
  }
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

void Vibrating::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case TICK:
      cushion->waitingToStand();
      break;
    case GET_UP:
      cushion->initial();
      break;
    deafult:
      break;
  }
}

WaitingToStand::WaitingToStand(CushionHardware *hardware) : State(hardware) {}

void WaitingToStand::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case GET_UP:
      cushion->standing();
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

void Standing::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case WDT:
      counter++;
      if (counter > WAIT_5_MINS) {
        cushion->flashing();
      }
      break;
    default:
      break;
  }
}

Flashing::Flashing(CushionHardware *hardware) : State(hardware) {}

void Flashing::enter() {
  hardware->configureTimer1(SCALE1024);
  hardware->loadTimer1(oneSecondCount);
  hardware->enableTimer1();
  hardware->ledOn();
}

void Flashing::exit() {
  hardware->disableTimer1();
  hardware->ledOff();
}

void Flashing::handleEvent(Event event, Cushion *cushion) {
  switch (event) {
    case TICK:
      cushion->waitingToSit();
      break;
    case SIT_DOWN:
      cushion->buzzing();
      break;
    deafult:
      break;
  }
}

WaitingToSit::WaitingToSit(CushionHardware *hardware) : State(hardware) {}

void WaitingToSit::enter() {
    hardware->enableWDTimer();
    hardware->sleep();
    counter = 0;
}

void WaitingToSit::exit() {
   hardware->disableWDTimer();
}

Cushion::Cushion(CushionHardware *hardware) {
  _initial = new Initial(hardware);
  _buzzing = new Buzzing(hardware);
  _sitting = new Sitting(hardware);
  _vibrating = new Vibrating(hardware);
  _waitingToStand = new WaitingToStand(hardware);
  _standing = new Standing(hardware);
  _flashing = new Flashing(hardware);
  _waitingToSit = new WaitingToSit(hardware);
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

void Cushion::flashing() {
 nextState(_flashing);
}

void Cushion::waitingToSit() {
 nextState(_waitingToSit);
}

  
