#include "bsp.h"

BSP bsp;

class State;

class Cushion {
  private:
    State *waiting;
    State *sitting;
    State *current;
  public:
    Cushion();
    void handleEvent(Event event);
    void standUp();
    void sitDown();
};

// define State class

class State {
  public:
    virtual void handleEvent(Event event, Cushion* cushion) {}
    virtual void enter() {}
};

// define Substates

const int timer1count = 0;

class Waiting: public State {
  void handleEvent(Event event, Cushion* cushion) {
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
  
};

class Sitting: public State {
  void handleEvent(Event event, Cushion* cusion) {
  }
};

Cushion::Cushion() {
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

