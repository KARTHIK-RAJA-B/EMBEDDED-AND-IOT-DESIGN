
int ip1=D0;
//int ip2=D1;
void setup() 
{
  pinMode(D0,OUTPUT);
  //pinMode(D1,OUTPUT);
}
void loop() {
 digitalWrite(D0,HIGH);
 //digitalWrite(ip2,LOW);
 delay(3000);
 //digitalWrite(ip2,HIGH);
 digitalWrite(D0,LOW);
 delay(3000);
}
