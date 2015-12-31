#ifndef events_h_
#define events_h_


typedef enum Event { NON_EVENT, TICK, WDT, SIT_DOWN, GET_UP};

class EventBuffer {
    public:
      EventBuffer(int max_events);
      ~EventBuffer();
      int capacity();
      boolean hasMore();
      Event next();
      int post(Event event);
    private:
      const int max_events;
      Event * buffer;
      int head;
      int tail;
};

#endif
