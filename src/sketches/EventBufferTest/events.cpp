#include "Arduino.h"
#include "events.h"

EventBuffer::EventBuffer(int n) : max_events(n) {
  buffer = (Event*) malloc((max_events+1)*sizeof(Event));
}

int EventBuffer::capacity() {
  return max_events;
}

Event EventBuffer::next() {
  return NON_EVENT;
}

void EventBuffer::post(Event event) {
  
}
