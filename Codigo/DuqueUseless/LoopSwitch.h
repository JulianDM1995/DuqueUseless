#ifndef LoopSwitch_h
#define LoopSwitch_h

#include "Arduino.h"

#define NO_EVENT -1
#define CHANGED_ON 0
#define CHANGED_OFF 1
#define SWITCH_ON true
#define SWITCH_OFF false

class LoopSwitch {
  public:
    LoopSwitch();
    LoopSwitch(int pin);
    LoopSwitch(int pin, int debounceTime);

    int getEvent();
    int getStatus();
    
    int debounceTime = 50;
    bool status;
  private:
    int pin;
    int type;
    unsigned long previousMillis = 0;
    bool inDebounce = false;
};

#endif
