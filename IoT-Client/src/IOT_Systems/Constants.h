#pragma once

#include <Arduino.h>

class Constants
{
public:
    static const char* ssid;
    static const char* password;
    
    static const String host;
    static const int port;

    static const unsigned long timerDelay;
};