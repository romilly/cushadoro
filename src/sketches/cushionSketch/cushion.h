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
    Cushion(BSP *bsp);
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
  public:
    virtual void handleEvent(Event event, Cushion* cushion);
    Waiting(BSP *bsp);
  private:
    BSP *bsp; 
};

class Sitting: public State {
  void handleEvent(Event event, Cushion* cusion) {
  }
};


#endif
