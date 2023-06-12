#define BLYNK_TEMPLATE_ID "TMPLLC0zdzoT"
#define BLYNK_TEMPLATE_NAME "Air Quality Manager"
#define BLYNK_AUTH_TOKEN "dSdiWc4jmT2FaUfu_4kS-flqeAM8Sw9M"
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "dSdiWc4jmT2FaUfu_4kS-flqeAM8Sw9M"; //Enter the Auth code which was send by Blink
char ssid[] = "KR";  //Enter your WIFI Name
char pass[] = "KRraja@07";  //Enter your WIFI Password

void Ronaldo() {
  int r = analogRead(A0);
  bool l = digitalRead(D4);

  r = map(r, 0, 1023, 100, 0);
  if (isnan(r))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, r);  //V2 is for Rainfall
  void setup() 
  {
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(10L, Ronaldo);
  }

  void loop() 
  {
  Blynk.run(); 
  timer.run(); 
  }
}
