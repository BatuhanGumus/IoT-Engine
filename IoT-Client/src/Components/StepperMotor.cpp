#include "StepperMotor.h"

const int stepsPerRevolution = 2038;

StepperMotor::StepperMotor(String _nameTag, uint8_t _pin1, uint8_t _pin2, uint8_t _pin3, uint8_t _pin4) : IOT(_nameTag)
{
  this->pin1 = _pin1;
  this->pin2 = _pin2;
  this->pin3 = _pin3;
  this->pin4 = _pin4;

  pinMode(this->pin1, OUTPUT);
  pinMode(this->pin2, OUTPUT);
  pinMode(this->pin3, OUTPUT);
  pinMode(this->pin4, OUTPUT);
}

void StepperMotor::OnStep(int dir)
{
  if(dir > 0)
  {
    switch(step_number){
      case 0:
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
      case 1:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
      case 2:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      break;
      case 3:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      break;
    } 
  }
  else
  {
    switch(step_number)
    {
      case 0:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
      break;
      case 1:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
      break;
      case 2:
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
      break;
      case 3:
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    } 
  }
  step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}

void StepperMotor::OnStart()
{
  
}

void StepperMotor::OnUpdate()
{
  OnStep(motorDir);
  delay(2);
}

void StepperMotor::OnCall(JSONVar inp)
{
  motorDir = inp["direction"];
  Serial.println(motorDir);
}