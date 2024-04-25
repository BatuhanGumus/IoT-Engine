#include <Arduino.h>
#include "IOT_Systems/IOT.h"
#include "IOT_Systems/ActionTimer.h"
#include "IOT_Systems/WifiConnection.h"
#include "IOT_Systems/Http.h"
#include "IOT_Systems/Constructer.h"

void setup() 
{
  Serial.begin(9600); 

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Constructer::ConstructThings();

  for (int i = 0; i < Constructer::thingCount; i++)
  {
    if(Constructer::allThings[i] != nullptr) Constructer::allThings[i]->OnStart();
  }
  
  WifiConnection::Connect();
}

void loop()
{
  for (int y = 0; y < Constructer::thingCount; y++)
  {
    Constructer::allThings[y]->OnUpdate();
  }

  if (ActionTimer::TimeToAct() && WifiConnection::IsConnected()) 
  {
    for (int j = 0; j < Constructer::thingCount; j++)
    {
      if(Constructer::allThings[j] != nullptr)
      {
        String inp = Http::Request(Constructer::allThings[j]->nameTag);
        if(inp != "ERROR" && inp != Constructer::allThings[j]->lastInp)
        {
          JSONVar obj = JSON.parse(inp);

          if (JSON.typeof(obj) == "undefined") Serial.println("Parsing input failed!"); 
          else Constructer::allThings[j]->OnCall(obj);

          Constructer::allThings[j]->lastInp = inp;
        }
      }
    }
  }
}