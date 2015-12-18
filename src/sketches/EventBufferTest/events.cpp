#include "Arduino.h"
#include "events.h"

EventBuffer::EventBuffer(int n) : max_events(n), head(0), tail(0) {
  buffer = (Event*) malloc((max_events+1)*sizeof(Event));
}

EventBuffer::~EventBuffer() {
  free(buffer);
}

int EventBuffer::capacity() {
  return max_events;
}

Event EventBuffer::next() {
  if (head == tail)
    return NON_EVENT;
  Event result = buffer[tail];
  tail += 1;
  if (tail > max_events)
    tail = 0;
   return result;
}

int EventBuffer::post(Event event) {
  int next = head+1;
  if (next > max_events)
    next = 0;
  if (next == tail)
    return -1;
  buffer[head] = event;
  head = next;
  return 0;
}
