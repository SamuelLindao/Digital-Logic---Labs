#include <Servo.h>

Servo servo1;

void setup() {
  servo1.attach(7);

}
int fn = 90;

void loop() {
  for (int i = 90; i > 60; i--) {
    servo1.write(i);
  }
  delay(1000);
  for (int i = 60; i < 90; i++) {
    servo1.write(i);
  }
  delay(1000);
  
}
