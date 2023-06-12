#define BLYNK_PRINT Serial  
 #include <ESP8266WiFi.h>  
 #include <BlynkSimpleEsp8266.h>  
 BlynkTimer timer;  
 char auth[] = "**********************"; //Auth code sent via Email  
 char ssid[] = "***********"; //Wifi name  
 char pass[] = "***********"; //Wifi Password   
 BLYNK_WRITE(V0) 
 {  
  int isButtonPressed = digitalRead(D0);  
  if (isButtonPressed==1) {  
    digitalWrite(D1, HIGH);
    Serial.println("LED ON");
  
  }  
  else 
  {  
    digitalWrite(D1, LOW);
    Serial.println("LED OFF");
  }  
 }  
 void setup()  
 {  
 Serial.begin(9600);  
 Blynk.begin(auth, ssid, pass);  
 pinMode(D0,INPUT);  
 pinMode(D1,OUTPUT);   
 }  
 void loop()  
 {  
  Blynk.run();   
 }  
