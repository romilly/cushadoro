#ifndef cushion_h_
#define cushion_h_

#include "cushion_hardware.h"
#include <events.h>

class State;

class Cushion {
  private:
    State * _current;
    State * _initial;
    State * _buzzing;
    State * _sitting;
    State * _vibrating;
    void nextState(State * nextState);
  public:
    Cushion(CushionHardware *hardware);
    void handleEvent(Event event);
    void initial();
    void buzzing();
    void sitting();
    void vibrating();
};

class State {
  public:
    State(CushionHardware *hardware);
    virtual void handleEvent(Event event, Cushion *context) {}
    virtual void enter() {}
    virtual void exit() {}
  protected:
     CushionHardware *hardware;
};


class Initial: public State {
  public:
    virtual void handleEvent(Event event, Cushion *context);
    Initial(CushionHardware *hardware);
};


class Buzzing: public State {
  public:
    Buzzing(CushionHardware *hardware);
    virtual void handleEvent(Event event, Cushion *context);
    virtual void enter();
    virtual void exit();
};


class Sitting: public State {
   public:
     Sitting(CushionHardware *hardware);
     virtual void handleEvent(Event event, Cushion *context);
     virtual void enter();
     virtual void exit();
   private:
     int counter = 0;
};

class Vibrating: public State {
   public:
     Vibrating(CushionHardware *hardware);
     virtual void handleEvent(Event event, Cushion *context);
     virtual void enter();
     virtual void exit();
};


#endif
