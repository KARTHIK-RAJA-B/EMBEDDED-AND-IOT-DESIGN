
#define BLYNK_TEMPLATE_ID "TMPLnNss8eBQ"
#define BLYNK_DEVICE_NAME "led blinking"
#define BLYNK_AUTH_TOKEN "HK0yT-ZrJEzUvMt3QJXTCpXS2EahZa7K"

#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BLYNK_AUTH_TOKEN";
char ssid[] = "ARSHATH"; 
char pass[] = "asdfghjkl";

//int sensorpin = A0;
int sensorvalue =0;

void setup() 
{

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);  
} 


BLYNK_WRITE(V0)
{
  
}

void loop() 
{
  Blynk.run();
  int sensorvalue = analogRead(34); 
  Blynk.virtualWrite(sensorvalue);
  Serial.println(sensorvalue);
}
