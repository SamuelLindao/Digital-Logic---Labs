#include "Ultrasonic.h"

const int echoPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)

const int trigPin = 8; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO ARDUINO

int distance;

void setup() {

Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
}

bool value = 0;
void loop() {

// Pass INC as a parameter to get the distance in inches

distance = ultrasonic.read();

Serial.print("Distance in CM: ");

Serial.println(distance);
if(distance <= 30  && distance > 20 )
{
     tone(10, 1000);

  // Serial.println(value);
}
if(distance >= 10 && distance <= 20) {
  digitalWrite(9, HIGH);
     tone(10, 2000);

}


delay(1000);

}