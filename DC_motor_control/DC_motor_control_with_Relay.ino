//Connect 5V and the ground of the IC to 5V and the ground of Arduino, respectively.
//Connect the motor to pins 2 and 3 of the IC.
//Connect IN1 of the IC to pin 8 of Arduino.
//Connect IN2 of the IC to pin 9 of Arduino.
//Connect EN1 of IC to pin 2 of Arduino.
//Connect SENS A pin of IC to the ground.
//Connect Arduino using Arduino USB cable and upload the program to Arduino using Arduino IDE software.
//Provide power to Arduino board using power supply, battery, or USB cable.

const int pwm = 2 ; //initializing pin 2 as pwm
const int in_1 = 8 ;
const int in_2 = 9 ;
//For providing logic to L298 IC to choose the direction of the DC motor

void setup() {
   pinMode(pwm,OUTPUT) ; //we have to set PWM pin as output
   pinMode(in_1,OUTPUT) ; //Logic pins are also set as output
   pinMode(in_2,OUTPUT) ;
}

void loop() {
   //For Clock wise motion , in_1 = High , in_2 = Low
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,LOW) ;
   analogWrite(pwm,255) ;
   /* setting pwm of the motor to 255 we can change the speed of rotation
   by changing pwm input but we are only using arduino so we are using highest
   value to driver the motor */
   //Clockwise for 3 secs
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(1000) ;
   //For Anti Clock-wise motion - IN_1 = LOW , IN_2 = HIGH
   digitalWrite(in_1,LOW) ;
   digitalWrite(in_2,HIGH) ;
   delay(3000) ;
   //For brake
   digitalWrite(in_1,HIGH) ;
   digitalWrite(in_2,HIGH) ;
   delay(1000) ;
}
//The motor will run first in the clockwise (CW) direction for 3 seconds and then counter-clockwise (CCW) for 3 seconds.
