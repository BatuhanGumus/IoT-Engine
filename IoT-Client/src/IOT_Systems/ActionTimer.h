#pragma once

class ActionTimer
{
private:
    static unsigned long lastTime;
    
public:
    static bool TimeToAct();
};

