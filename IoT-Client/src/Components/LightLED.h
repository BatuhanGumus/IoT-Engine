#pragma once

#include "IOT_Systems/IOT.h"

class LightLED : public IOT
{
private:
    uint8_t pin;
public:
    LightLED(String _nameTag, uint8_t _pin);
    void OnStart();
    void OnCall(JSONVar inp);
};