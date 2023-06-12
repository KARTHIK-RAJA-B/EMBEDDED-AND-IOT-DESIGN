#define BLYNK_TEMPLATE_ID "TMPLG-CEADel"
#define BLYNK_DEVICE_NAME "switchcontrol"
#define BLYNK_AUTH_TOKEN "AWU9XzxHHsQEHlIylNG3vx0QhVoCOiKp"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Nandhini Ramalingam";
char pass[] = "ponlakshminandhini";

BLYNK_WRITE(V0)
{
  {
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D0, LOW);
    Serial.println("LED OFF");
  }
  if(value == 1)
  {
     digitalWrite(D0, HIGH);
     Serial.println("LED ON");
  }
  }
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  analogWrite(D0, pinValue);
  Serial.print("V0 Slider value is: ");
  Serial.println(pinValue);
}

BLYNK_WRITE(V1)
{
  {
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D1, LOW);
    Serial.println("LED OFF");
  }
  if(value == 1)
  {
     digitalWrite(D1, HIGH);
     Serial.println("LED ON");
  }
  }
  int pinValue = param.asInt(); 
  analogWrite(D1, pinValue);
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}

BLYNK_WRITE(V2)
{
  {
  int value = param.asInt();
  Serial.println(value);
  if(value == 0)
  {
    digitalWrite(D2, LOW);
    Serial.println("LED OFF");
  }
  if(value == 1)
  {
     digitalWrite(D2, HIGH);
     Serial.println("LED ON");
  }
  }
  int pinValue = param.asInt(); 
  analogWrite(D2, pinValue);
  Serial.print("V2 Slider value is: ");
  Serial.println(pinValue);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  
}
