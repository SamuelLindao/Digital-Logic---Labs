#define ledPin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  TCCR1A = 0;
  TCCR1B = 0;

  TCCR1B |= (1 < CS10)|(1 << CS12);

  TCNT1 = 0x0000;
  TIMSK1 |= (1 << TOIE1);
}

void loop() {
  // put your main code here, to run repeatedly:

}

ISR(TIMER1_OVF_vect)
{
   TCNT1 = 0x0000;
   digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
}