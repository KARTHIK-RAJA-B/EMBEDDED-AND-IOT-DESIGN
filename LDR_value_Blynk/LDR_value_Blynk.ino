#define BLYNK_TEMPLATE_ID "TMPLVyYPd7Ar"
#define BLYNK_DEVICE_NAME "LDR led blink"
#define BLYNK_AUTH_TOKEN "Za1hRHFLR_itw_d71AgxCHetBRoolc7v"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "BLYNK_AUTH_TOKEN";
char ssid[] = "ECE IOT"; 
char pass[] = "$eceeceiot@2k22";
int mq2 = A0;
int data =0;
BlynkTimer timer;
void setup() 
{

  
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
} 
void getSendData()
{
int data = analogRead(mq2); 
  Blynk.virtualWrite(V0, data);
  Serial.print(data);
 
}
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
