#include <events.h>
#include "bsp.h"


BSP bsp;
EventBuffer eb = EventBuffer(4);
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
        bsp.blinkLed();
        break;
      case NON_EVENT:
        break;
      default:
        break;
    }
  }
  
};

class Seated: public State {
  void handleEvent(Event event, Cushion* cusion) {
  }
};

Cushion::Cushion() {
  waiting = new Waiting;
  sitting = new Seated;
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
  Serial.begin(9600);
}

void loop() {
  eb.post(TICK);
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
    Serial.print("event = ");
    Serial.println(next);
    delay(300);
  }
}
