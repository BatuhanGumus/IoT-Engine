# IoT-Engine

[![GitHub license](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)](/LICENSE)

An IoT engine with a client and a server component used to handle server communication to set the states of IoT devices

----

## Features
#### Server
- Save & manipulate custom JSON's for client states
#### Client
- Connect to Wifi to access the server
- Listen to state changes in the server
- Parse JSON data from the server
- OnCall and OnUpdate for ease of hardware control

## Example use
My goal is to have a gyro sensor on my curtain and a stepper motor turning the curtain to match the rotation I want being kept on the server
<img src="/docs/projectPic.jpeg">

## Requirements
1) [Node JS](https://nodejs.org/en) for the server
2) [PlatformIO](https://platformio.org/) on VSCode for building to Arduino
3) An [ESP8266](https://en.wikipedia.org/wiki/ESP8266#:~:text=The%20ESP8266%20is%20a%20low,Espressif%20Systems) board for wifi connectivity on client hardware

## Setting up the IoT Server
1) Create data for your client in [storage.js](/IoT-Handler-Server/storage.js)
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
2) run server.js with `node server.js`

## Setting up the IOT client
1. Use [PlatformIO documentation](https://platformio.org/install/ide?install=vscode) to install PlatformIO for VSCode to build C++ files on your ESP8266
2. Edit [Constants.cpp](/IoT-Client/src/Constants.cpp) for Wifi Connection
    ```cpp
    // =========== WIFI Details ==============
    const char* Constants::ssid = "your-wifi-name";
    const char* Constants::password = "your-wifi=password";

    // =========== Server Details ==============
    const String Constants::host = "your-server-IP";
    const int Constants::port = 8080;
    ```
3. Code custom IOT functinoality
Base a class off of the IOT class. Chech [LightLED.cpp](/IoT-Client/src/Components/LightLED.cpp) for an example
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
      bool status = inp["status"];
      if(status == true)
          digitalWrite(pin, HIGH);
      else
          digitalWrite(pin, LOW);
    }
    ```
4. Create an IOT device in [Constructor.cpp](/IoT-Client/src/Constructer.cpp)
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
5. Build with PlatformIO

## Future Plans
Still working on the gyro and the stepper motor component for the mentioned project in the Example Use section