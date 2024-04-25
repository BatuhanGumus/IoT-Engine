#pragma once

#include "IOT_Systems/IOT.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

class Gyro : public IOT
{
private:
    Adafruit_MPU6050 mpu;
public:
    Gyro(String _nameTag);
    void OnStart();
    void OnUpdate();
};