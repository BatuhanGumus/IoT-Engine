# IoT-Engine
An IoT engine with a client and a server component used to handle server communication to set the states of IoT devices


----

[![GitHub license](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)](/LICENSE)

### Features
#### Server
- Save & manipulate custom JSON's for client states
#### Client
- Connect to Wifi to access the server
- Listen to state changes in the server
- Parse JSON data from the server
- OnCall and OnUpdate for ease of hardware control

## Example use

## Requirements

## Setting up the IOT Server
#### 1. install dependencies with `npm install`
#### 2. Create data for your client in storage.js
```js
var storage = function() {
   this.data = {
       "rgbLight": {"red": 0, "green": 0, "blue": 255},
       "stepperMotor": {"direction": 1},
   };
   this.functions = {
       "testFunction": testFunction,
   };
 };

 function testFunction()
 {
     console.log("test function called");
 }
```
#### 4. run server.js with `node server.js`

## Setting up the IOT client
#### 1. install PlatformIO on VSCode to build C++ files on your ESP8266
#### 2. Edit Constants.cpp for Wifi Connection
```cpp
// =========== WIFI Details ==============
const char* Constants::ssid = "your-wifi-name";
const char* Constants::password = "your-wifi=password";

// =========== Server Details ==============
const String Constants::host = "your-server-IP";
const int Constants::port = 8080;
```
#### 3. Code custom IOT functinoality
Base a class off of the IOT class. Chech src/Components/LightLED.cpp for an example
```cpp
LightLED::LightLED(String _nameTag, uint8_t _pin) : IOT(_nameTag)
{
  this->pin = _pin;
}

void LightLED::OnStart()
{
  pinMode(pin, OUTPUT);
}

void LightLED::OnCall(JSONVar inp)
{
  //bool status = inp["status"];
  bool status = true;

  if(status == true)
  {
    digitalWrite(pin, HIGH);
  }
  else
  {
    digitalWrite(pin, LOW);
  }
}
```
#### 4. Create an IOT device in Constructor.cpp
```cpp
const int Constructer::thingCount = 1; // Amount of internet connected proccess run in code
IOT** Constructer::allThings = new IOT*[thingCount];

void Constructer::ConstructThings()
{
    // === construct all internet connected things ===
    // things array = thing constructor ( name, pins to use )
    allThings[0] = new LightLED("blueLight", 4);
}
```
#### 5. Build with PlatformIO
