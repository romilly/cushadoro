#include <events.h>
#include "bsp.h"

const int timer1count = 0;
BSP bsp;
EventBuffer eb = EventBuffer(4);
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  eb.post(TICK);
}
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


class Waiting: public State {
  void handleEvent(Event event, Cushion* cushion) {
    switch (event) {
      case SIT_DOWN:
        cushion->sitDown();
        break;
      case TICK:
        bsp.toggleLed();
        bsp.loadTimer1(timer1count);   // preload timer
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


Cushion* cushion = new Cushion;


void setup() {
  bsp.configureTimer1(timer1count);  
}

void loop() {
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
  }
}
