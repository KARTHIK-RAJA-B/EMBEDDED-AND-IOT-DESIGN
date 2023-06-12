


#define BLYNK_TEMPLATE_ID "TMPLyA8uSCcd"
#define BLYNK_DEVICE_NAME "HX711"
#define BLYNK_AUTH_TOKEN "uHvexgWD1rvWVx037FTI_YsYe5dXGkWu"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "HX711.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ECE IOT";
char pass[] = "$eceeceiot@2k22";
 
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#define LOADCELL_DOUT_PIN D5;
#define LOADCELL_SCK_PIN  D6;
HX711 scale;

int rbutton = D4; 
float weight;
float calibration_factor = -8550260.00; 

void setup() 
{
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  pinMode(D4, INPUT);
  scale.begin(D5,D6);
  scale.set_scale();
  scale.tare(); 
  long zero_factor = scale.read_average();
}

void loop() 
{
  
  scale.set_scale(calibration_factor); 
  weight = scale.get_units(5); 
  Blynk.virtualWrite(V3, weight);
  delay(2000);
  Serial.print("Weight: ");
  Serial.print(weight);
  Serial.println(" KG");
  Serial.println(); 
  Blynk.run();
}
BLYNK_WRITE(V0)
{
  if ( digitalRead(rbutton) == 1)
  {
  scale.set_scale();
  scale.tare(); 
  }
}
