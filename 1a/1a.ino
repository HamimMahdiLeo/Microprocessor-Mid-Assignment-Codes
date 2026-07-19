#define PIN_USED 5

void setup()
{
  pinMode(PIN_USED, OUTPUT); // Timer1 normal mode
  TCCR1A = 0;
  TCCR1B = 0b00000101;
  TCNT1 = 0;
}

void loop()
{
  int count = 6627; // for 522ms
  if (TCNT1 >= count) {
    TCNT1 = 0;
    digitalWrite(PIN_USED, !digitalRead(PIN_USED));
  }
}