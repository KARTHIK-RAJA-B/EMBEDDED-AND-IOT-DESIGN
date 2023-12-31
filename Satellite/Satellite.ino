#include <Servo.h>

#include <Blynk.h>

#define BLYNK_TEMPLATE_ID "TMPLkPrZ3qmk"
#define BLYNK_DEVICE_NAME "SERVO ANTENNA"
#define BLYNK_AUTH_TOKEN "rwveVDIscF2VBObDZfxB1ttmlkWYZjJx"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Django";  // type your wifi name
char pass[] =  "KRraja@07";  // type your wifi password

Servo servo;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  servo.attach(D0);
}

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D0, LOW);
    Serial.println("LED ON");
  }
  if(value == 1)
  {
     digitalWrite(D0, HIGH);
     if(D0==1)
     {
      servo.write(0);
      delay(1000);
      servo.write(180);
      delay(1000);
     }
     Serial.println("LED OFF");
  }
}


void loop()
{
  Blynk.run();
}
