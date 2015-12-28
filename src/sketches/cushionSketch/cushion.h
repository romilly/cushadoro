#ifndef cushion_h_
#define cushion_h_

#include "bsp.h"
#include <events.h>

class State;
class Waiting;
class Sitting;

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
  public:
    virtual void handleEvent(Event event, Cushion* cushion); 
};

class Sitting: public State {
  void handleEvent(Event event, Cushion* cusion) {
  }
};


#endif
