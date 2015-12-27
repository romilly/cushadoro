#include <events.h>
#include "bsp.h"


BSP bsp;
EventBuffer eb = EventBuffer(4);
int timer1_counter;
ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
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
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  //timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  timer1_counter = 0;
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();     
}

void loop() {
  Event next;
  while(next = eb.next()) {
    cushion->handleEvent(next);
  }
}
