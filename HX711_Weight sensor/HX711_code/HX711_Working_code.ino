#include <ESP8266WiFi.h>
#include "HX711.h"
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#define BLYNK_PRINT Serial

#define sck D6;
#define dt D5;
 
const char *ssid = "Django"; 
const char *pass = "KRraja@07";
char auth[] = "LWjD5tE_N5cBMn1VEPNHbQJAR9trkeWc";   
 
WiFiClient client;
 
HX711 scale;
 
int rbutton = D4; 
double weight;
float calibration_factor =-633608.000;
 
void setup() 
{
  Serial.begin(115200);
  pinMode(rbutton, INPUT_PULLUP);
  scale.begin(D5,D6);
  scale.set_scale();
  scale.tare(); 
  float zero_factor = scale.read_average();
  Blynk.begin(auth, ssid, pass);

  
 
  WiFi.begin(ssid, pass);
{
  delay(1000);
  Serial.println(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  delay(1000);
}
 
void loop() 
 
{
 
  Blynk.run();
  scale.set_scale(calibration_factor);
 
  weight = scale.get_units();
  
  Blynk.virtualWrite(V3, weight);
  delay(1000);
  
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" KG");
  Serial.println();

//if ( digitalRead(rbutton) == HIGH)
//{
  //scale.set_scale();
 // scale.tare(); 
//}
 
}
