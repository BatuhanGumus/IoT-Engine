#include "LightRGB.h"


LightRGB::LightRGB(String _nameTag, uint8_t _redPin, uint8_t _greenPin, uint8_t _bluePin) : IOT(_nameTag)
{
    this->redPin = _redPin;
    this->greenPin = _greenPin;
    this->bluePin = _bluePin;
}

void LightRGB::OnStart()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW); 

    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}

void LightRGB::OnCall(JSONVar inp)
{
    analogWrite(redPin, inp["red"]);
    analogWrite(greenPin, inp["green"]);
    analogWrite(bluePin, inp["blue"]);
}