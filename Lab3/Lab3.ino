int counter =0;

void setup() {
  counter = 0;
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  counter += digitalRead(7) == HIGH? 1 : 0;
  digitalWrite(8,counter % 6 == 0 && counter != 0);


  Serial.println(digitalRead(7));
  Serial.print(">>");
  Serial.print(counter);

  if(counter == 6) counter =0 ;

  delay(100);
}
