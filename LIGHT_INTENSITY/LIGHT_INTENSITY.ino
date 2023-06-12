int K =D0 ;
int a = 0;

void setup() {
  pinMode(D0, OUTPUT); // LED control pin is 3, a PWM capable pin
}

void loop() {
  for (a = 0 ; a < 256 ; a++) {
    analogWrite(K, a);

  }
  for (a = 255 ; a >= 0 ; a--) {
    analogWrite(K, a);
 
  }
  delay(200);
}
