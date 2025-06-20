#include <Servo.h>

Servo servo;
void setup() {
  Serial.begin(9600);
  servo.attach(7);
 servo.write(0); 

  delay(1000);
  servo.write(120);
  delay(1000);
}
int value= 0;
void loop() {
  // put your main code here, to run repeatedly:
 
}
