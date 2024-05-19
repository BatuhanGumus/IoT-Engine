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

## Setting up the IOT Server
1) install dependencies with `npm install`
2) Create data for your client in storage.js
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
4) run server.js with `node server.js`

## Setting up the IOT client
1) Edit Constants.cpp for Wifi Connection
2) Code custom IOT functinoality
3) Create an IOT device in Constructor.cpp
