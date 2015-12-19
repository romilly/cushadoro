typedef enum Event { NON_EVENT, TICK, SIT_DOWN, GET_UP};

class EventBuffer {
    public:
      EventBuffer(int max_events);
      ~EventBuffer();
      int capacity();
      Event next();
      int post(Event event);
    private:
      const int max_events;
      Event * buffer;
      int head;
      int tail;
};

