
#include "HX711.h"
#define LOADCELL_DOUT_PIN D5;
#define LOADCELL_SCK_PIN D6
HX711 scale;
void setup() {
  Serial.begin(115200);
  scale.begin(D5,D6);
}

void loop() {

  if (scale.is_ready()) {
    
    scale.set_scale();    
    Serial.println("Tare... remove any weights from the scale.");
    delay(1000);
    scale.tare();
    Serial.println("Tare done...");
    Serial.print("Place a known weight on the scale...");
    delay(1000);
    long reading = scale.read();
    Serial.print("Result: ");
    Serial.println(reading);
  } 
  else {
    Serial.println("HX711 not found.");
  }
  delay(1000);
}
