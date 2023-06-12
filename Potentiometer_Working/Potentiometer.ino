
int led=D0;
int meter=A0;
long int val;
void setup() {
  pinMode(D0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val=analogRead(meter);
  val=map(val,0,1023,0,256);
  Serial.println(val);
  analogWrite(led,val);
  delay(1000);
}
