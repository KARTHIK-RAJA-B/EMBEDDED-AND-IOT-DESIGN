#include <Blynk.h>
#include <Servo.h>
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL_2AWm11p"
#define BLYNK_DEVICE_NAME "Antenna"
#define BLYNK_AUTH_TOKEN "ToiYVsHOen_Ih8q5QFLE_cgoIs1yroYc"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Naveen Kumar";
char pass[] = "9150519787";

Servo myservo;


BLYNK_WRITE(V0)
{
  
  //int value = param.asInt();
  //Serial.println(value);
  if(D1 == 0)
  {
    myservo.write(0);
    delay(1000);
    //Serial.println("LED OFF");
  }
  if(D1 == 1)
  {
    myservo.write(0);
    delay(1000);
    myservo.write(360);
    delay(1000);
  }
 }

 void setup()
 {
  pinMode(D1,INPUT);
  pinMode(D0,OUTPUT);
  myservo.attach(D0);
  Blynk.begin(auth, ssid, pass);
 }

void loop() 
{
  Blynk.run();
}
