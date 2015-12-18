typedef enum Event { NOTHING=0, TICK, SIT_DOWN, GET_UP};


class EventBuffer {
    public:
      EventBuffer(int max_events, Event* buffer);
    private:
      const int max_events;
      Event* buffer;
};
