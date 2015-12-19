#include <tinyarduinotest.h>
#include <events.h>
#include "Arduino.h"


const int MAX_CAPACITY = 3;
EventBuffer b = EventBuffer(MAX_CAPACITY);

void test_constructor_sets_capacity()
{
  EventBuffer b = EventBuffer(MAX_CAPACITY);
  ASSERT_EQUALS(MAX_CAPACITY, b.capacity());
}

void test_next_returns_non_event_if_buffer_is_empty() {
  EventBuffer b = EventBuffer(MAX_CAPACITY);
  ASSERT_EQUALS(NON_EVENT, b.next());
}

void test_next_returns_posted_events() {
  EventBuffer b = EventBuffer(MAX_CAPACITY);
  b.post(TICK);
  b.post(GET_UP);
  ASSERT_EQUALS(TICK, b.next());
  ASSERT_EQUALS(GET_UP, b.next());
  ASSERT_EQUALS(NON_EVENT, b.next());
}

void test_post_returns_0_until_buffer_full() {
  EventBuffer b = EventBuffer(MAX_CAPACITY);
  ASSERT_EQUALS(0, b.post(TICK));
  ASSERT_EQUALS(0, b.post(SIT_DOWN));
  ASSERT_EQUALS(0, b.post(GET_UP));
  ASSERT_EQUALS(-1, b.post(TICK));
}

void test_buffer_cycles() {
  EventBuffer b = EventBuffer(MAX_CAPACITY);
  b.post(TICK);
  b.post(SIT_DOWN);
  b.post(GET_UP);
  ASSERT_EQUALS(TICK, b.next());
  ASSERT_EQUALS(SIT_DOWN, b.next());
  ASSERT_EQUALS(0, b.post(TICK));
  ASSERT_EQUALS(GET_UP, b.next());
  ASSERT_EQUALS(TICK, b.next());
  ASSERT_EQUALS(NON_EVENT, b.next());
}

void setup() {
  Serial.begin(9600);
  RUN(test_constructor_sets_capacity);
  RUN(test_next_returns_non_event_if_buffer_is_empty);
  RUN(test_next_returns_posted_events);
  RUN(test_post_returns_0_until_buffer_full);
  RUN(test_buffer_cycles);
}

void loop() {
  TEST_REPORT();
  Serial.println(); 
}
