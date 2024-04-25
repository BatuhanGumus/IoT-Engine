#include "IOT_Systems/Constructer.h"

#include "Components/StepperMotor.h"
#include "Components/gyro.h"

const int Constructer::thingCount = 1; // Amount of internet connected proccess run in code
IOT** Constructer::allThings = new IOT*[thingCount];

void Constructer::ConstructThings()
{
    // === construct all internet connected things ===
    // things array = thing constructor ( name, pins to use )
    // allThings[0] = new Light("blueLight", 4);
}