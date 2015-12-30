#ifndef cushion_h_
#define cushion_h_

#include "cushion_hardware.h"
#include <events.h>

class State;
class Waiting;
class Sitting;

class Cushion {
  private:
    State *current;
  public:
    Cushion(CushionHardware *hardware);
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
    Waiting(CushionHardware *hardware);
  private:
    CushionHardware *hardware;
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
