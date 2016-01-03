#ifndef cushion_h_
#define cushion_h_

#include "cushion_hardware.h"
#include <events.h>

// TODO: add nextState method to Cushion; have cushion run enter and exit methods on states at change.
// State::HandleEvent bacomes void and loop jst delegates events

class State;
class Initial;
class Buzzing;
class Sitting;

class Cushion {
  private:
    State *current;
  public:
    Cushion(CushionHardware *hardware);
    void handleEvent(Event event);
    State * initial;
    State * buzzing;
    State * sitting;
};

class State {
  public:
    State(CushionHardware *hardware);
    virtual State * handleEvent(Event event, Cushion *context);
    virtual void enter() {}
    virtual void exit() {}
  protected:
     CushionHardware *hardware;
};

class Initial: public State {
  public:
    virtual State * handleEvent(Event event, Cushion *context);
    Initial(CushionHardware *hardware);
};


class Buzzing: public State {
  public:
    Buzzing(CushionHardware *hardware);
    virtual State * handleEvent(Event event, Cushion *context);
    virtual void enter();
    virtual void exit();
};

class Sitting: public State {
   public:
     virtual State * handleEvent(Event event, Cushion *context);
     Sitting(CushionHardware *hardware);

};


#endif
