void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  digitalWrite(8, (digitalRead(7) && digitalRead(6)));
  digitalWrite(9, (digitalRead(7) ^ digitalRead(6)));
  Serial.println( (digitalRead(7) ^ digitalRead(6)));
  

  delay(100);

}
