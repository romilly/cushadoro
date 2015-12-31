#ifndef cushion_h_
#define cushion_h_

#include "cushion_hardware.h"
#include <events.h>

class State;
class Initial;
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


class Initial: public State {
  public:
    virtual State * handleEvent(Event event);
    Initial(CushionHardware *hardware);
  private:
    CushionHardware *hardware;
    State *sitting; 
};

class Sitting: public State {
  public:
    Sitting(State * initial, CushionHardware *hardware);
    virtual State * handleEvent(Event event) {}
    virtual void enter();
  private:
    CushionHardware *hardware;
    State *initial;

};


#endif
