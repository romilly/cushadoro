#include "events.h"
#include "Arduino.h"

const int MAX_EVENTS = 10;
Event* _buffer[MAX_EVENTS+1] ;

EventBuffer::EventBuffer(const int MAX_EVENTS, Event* buf) {
  max_events = MAX_EVENTS;
  buffer = buf;
  
}
