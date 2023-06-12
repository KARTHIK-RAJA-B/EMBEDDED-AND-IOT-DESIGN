#define BLYNK_TEMPLATE_ID "TMPLpm2q99ys"
#define BLYNK_DEVICE_NAME "DHT11 AND GAS SENSOR"
#define BLYNK_AUTH_TOKEN "a2VvHZgYxykGaZ9JkXHoFODChi4A_26u"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Django";  // type your wifi name
char pass[] =  "KRraja@07";  // type your wifi password

#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN , DHTTYPE);
int mq2 = A0;
//int data =0;
BlynkTimer timer;


void sendSensor()
{
 float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, h);
  Blynk.virtualWrite(V1,t);
  Serial.println(t);
  Serial.println(h);
}
void getSendData()
{

int data = analogRead(mq2); 
  Blynk.virtualWrite(V3, data);
 
//}
  
void setup()
{
  
 Serial.begin(115200);
  Blynk.begin(auth, ssid, pass); 
  dht.begin();
  timer.setInterval(1000L, sendSensor);
  Serial.begin(115200);
  timer.setInterval(1000L, getSendData);
}

void loop()
{
  Blynk.run();
  timer.run();
}
