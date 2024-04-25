#pragma once

#include <Arduino.h>
#include <Arduino_JSON.h>

class IOT
{
public:
    String lastInp = "";
    String nameTag = "";

    IOT(String _nameTag);

    virtual void OnStart() {}
    virtual void OnCall(JSONVar inp) {}
    virtual void OnUpdate() {}
};
