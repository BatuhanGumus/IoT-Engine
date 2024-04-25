#include "LightLED.h"

LightLED::LightLED(String _nameTag, uint8_t _pin) : IOT(_nameTag)
{
  this->pin = _pin;
}

void LightLED::OnStart()
{
  pinMode(pin, OUTPUT);
}

void LightLED::OnCall(JSONVar inp)
{
  //bool status = inp["status"];
  bool status = true;

  if(status == true)
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}