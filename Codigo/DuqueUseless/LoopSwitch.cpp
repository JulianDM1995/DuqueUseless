#include "Arduino.h"
#include "LoopSwitch.h"

LoopSwitch::LoopSwitch() {}

LoopSwitch::LoopSwitch(int pin, int debounceTime)
{
  pinMode(pin, INPUT);
  this->pin = pin;
  this->debounceTime = debounceTime;
  status = digitalRead(pin);
}

LoopSwitch::LoopSwitch(int pin)
{
  pinMode(pin, INPUT);
  this->pin = pin;
  status = digitalRead(pin);
}

int LoopSwitch::getStatus()
{
  return digitalRead(pin) ? SWITCH_ON : SWITCH_OFF;
}

int LoopSwitch::getEvent()
{

  if (!inDebounce)
  {
    if (digitalRead(pin) != status)
    {
      inDebounce = true;
      previousMillis = millis();
    }
  }
  else
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= debounceTime)
    {
      inDebounce = false;
      status = digitalRead(pin);
      return status ? CHANGED_ON : CHANGED_OFF;
    }
  }

  return NO_EVENT;
}
