#include "WifiConnection.h"
#include "Constants.h"


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

void WifiConnection::Connect()
{
    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(Constants::ssid, Constants::password);

    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    digitalWrite(LED_BUILTIN, HIGH);
}

bool WifiConnection::IsConnected()  // check connection to wifi
{
  bool ret = WiFi.status()== WL_CONNECTED;
  if(ret == false)
  {
    Serial.println("WiFi Disconnected");
    digitalWrite(LED_BUILTIN, LOW);
    Connect();
  } 
  return ret;
}