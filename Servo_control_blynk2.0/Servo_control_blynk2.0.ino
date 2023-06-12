

/*
 * This program is property of SME Dehradun. for any query related to this program, 
 * contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor, 
 * then contact to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLcXVssMMy"
#define BLYNK_DEVICE_NAME "Automatic pet feeder"
#define BLYNK_AUTH_TOKEN "-vP_vdvydrYkv_K7_TS3PyroQz9A1Cqo"

#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
#include<ESP8266WiFi.h>
#include<Servo.h>
Servo servo;



char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "vivo";  // type your wifi name
char pass[] =  "1234567890";  // type your wifi password


BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V1, s0);
}
void setup()
{
  Serial.begin(115200);
  servo.attach(D0);
  Blynk.begin(auth, ssid, pass);
  delay(2000);  
}

void loop() 
{
  Blynk.run();
}
