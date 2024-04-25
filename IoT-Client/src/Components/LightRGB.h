#pragma once

#include "IOT_Systems/IOT.h"

class LightRGB : public IOT
{
private:
    uint8_t redPin, bluePin, greenPin;
public:
    LightRGB(String _nameTag, uint8_t _redPin, uint8_t _greenPin, uint8_t _bluePin);
    void OnStart();
    void OnCall(JSONVar inp);
};