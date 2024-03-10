#include <Arduino.h> 
#include <LiquidCrystal.h> 
#include <ArduinoJson.h>  
#include <Wire.h>  
#include <HTTPClient.h> 
#include "env.h"


LiquidCrystal My_LCD(22,23,5,18,19,21);

// put function declarations here:


void setup() {
  // put your setup code here, to run once: 

  // Initialize The LCD. Parameters: [ Columns, Rows ]
  My_LCD.begin(16, 2);
  // Clears The LCD Display
  //My_LCD.clear();
  //My_LCD.setCursor(0,0);
  // Display The First Message In Home Position (0, 0)
  //My_LCD.print("Hello World!");
  // Set The Cursor Position To: [ Col 5, Row 1]
  // The Next Message Will Start From The 6th Char Position in The 2nd Row
  // Note: 1st Row Has An Index of 0, The 2nd Row Has An Index of 1
  //My_LCD.setCursor(5, 1);
  // Display The Second Message In Position (5, 1)
 // My_LCD.print("GG izi");
  Serial.begin(9600); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  

}

void loop() {
  // put your main code here, to run repeatedly: 
  HTTPClient http; 
  
  http.begin(endpoint.c_str());  

  http.GET();  
  http.addHeader("api-key", api_key);
  int httpResponseCode = http.GET(); 

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String responseBody = http.getString(); 
    Serial.println(responseBody); 

    JsonDocument doc; 
    DeserializationError error = deserializeJson(doc, responseBody);

if (error){
    Serial.print("deserializeJson()failed: ");
    Serial.println(error.c_str());
    return;
   }
   String line_1 = doc["line_1"];  
   String line_2 = doc["line_2"]; 
   


  My_LCD.clear();
  My_LCD.setCursor(0,0); 
  My_LCD.print(line_1);  
  My_LCD.setCursor(0,1); 
  My_LCD.print(line_2); 

  }
}
// put function definitions here:
