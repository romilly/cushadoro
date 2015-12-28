#ifndef cushion_h_
#define cushion_h_

#include "bsp.h"
#include <events.h>

class State;
class Waiting;
class Sitting;

class Cushion {
  private:
    State *current;
  public:
    Cushion(BSP *bsp);
    void handleEvent(Event event);
};

// define State class

class State {
  public:
    virtual State * handleEvent(Event event) { return this; }
    virtual void enter() {}
};

// define Substates

class Waiting: public State {
  public:
    virtual State * handleEvent(Event event);
    Waiting(BSP *bsp);
  private:
    BSP *bsp;
    State *sitting; 
};

class Sitting: public State {
  public:
    Sitting(State * waiting);
    virtual State * handleEvent(Event event) {}
  private:
    State *waiting;
};


#endif
