typedef enum Event { NON_EVENT=0, TICK, SIT_DOWN, GET_UP};

class EventBuffer {
    public:
      EventBuffer(int max_events);
      int capacity();
      Event next();
      void post(Event event);
    private:
      const int max_events;
      const Event *buffer;
};

