#pragma once

#include "IOT_Systems/IOT.h"

class StepperMotor : public IOT
{
private:
    uint8_t pin1, pin2, pin3, pin4;
    int step_number = 0;
    int motorDir = +1;
    void OnStep(int dir);
public:
    StepperMotor(String _nameTag, uint8_t _pin1, uint8_t _pin2, uint8_t _pin3, uint8_t _pin4);
    void OnStart();
    void OnUpdate();
    void OnCall(JSONVar inp);
};