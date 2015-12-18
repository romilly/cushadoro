#include "Arduino.h"
#include "events.h"
#include "tinyarduinotest.h"

const int MAX_CAPACITY = 4;
EventBuffer b = EventBuffer(MAX_CAPACITY);

void test_constructor_sets_capacity()
{
  ASSERT_EQUALS(MAX_CAPACITY, b.capacity());
}

void test_next_returns_non_event_if_buffer_is_empty() {
  ASSERT_EQUALS(NON_EVENT, b.next());
}

void test_next_returns_posted_events() {
  b.post(TICK);
  b.post(GET_UP);
  ASSERT_EQUALS(TICK, b.next());
  ASSERT_EQUALS(GET_UP, b.next());
  ASSERT_EQUALS(NON_EVENT, b.next());
}

void setup() {
  Serial.begin(9600);
  RUN(test_constructor_sets_capacity);
  RUN(test_next_returns_non_event_if_buffer_is_empty);
  RUN(test_next_returns_posted_events);
 
}

void loop() {
  TEST_REPORT();
  Serial.println(); 
}
