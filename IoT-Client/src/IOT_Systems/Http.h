#pragma once

#include "ArduinoOTA.h"

class Http
{
public:
    static String Request(String nameTag, String funcType = "GET", String setDetails = ""); // send http req
};