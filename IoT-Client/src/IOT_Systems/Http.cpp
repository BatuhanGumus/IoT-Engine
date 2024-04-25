#include "Http.h"
#include <ESP8266HTTPClient.h>
#include "Constants.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

String Http::Request(String nameTag, String funcType, String setDetails)  // send http req
{
    WiFiClient client;
    HTTPClient http;

    String serverPath = "http://" + Constants::host + ":" + Constants::port+ "/" + funcType + "/" + nameTag + "/" + setDetails;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());
    
    // Send HTTP GET request
    int httpResponseCode = http.GET();
    
    String out = "";

    if (httpResponseCode>0) 
    {
      out = http.getString();
    }
    else 
    {
      Serial.print("Error code: ");
      //Serial.print(httpResponseCode);
      Serial.println(http.errorToString(httpResponseCode));
      out = "ERROR";
    }
    // Free resources
    http.end();

    return out;
}
