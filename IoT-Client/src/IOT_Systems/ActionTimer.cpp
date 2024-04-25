#include "ActionTimer.h"
#include <Arduino.h>
#include "Constants.h"

unsigned long ActionTimer::lastTime = 0;

bool ActionTimer::TimeToAct()
{
    bool ret = (millis() - lastTime) > Constants::timerDelay;
    if(ret) lastTime = millis();
    return ret;
}