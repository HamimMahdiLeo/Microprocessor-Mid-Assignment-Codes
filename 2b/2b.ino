const int switchPin = 2;
const int ledPin = 12;

volatile bool switchState = LOW;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  bool reading = digitalRead(switchPin);

  if (reading == HIGH) {
    delayTimer1(30); // debounce delay
    if (digitalRead(switchPin) == HIGH) {
      digitalWrite(ledPin, HIGH);
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}

// Timer1 based delay (approx)
void delayTimer1(int ms) {
  for (int i = 0; i < ms; i++) {
    TCNT1 = 0;
    TCCR1B = (1 << CS11) | (1 << CS10); // prescaler 64
    while (TCNT1 < 250); // ~1ms delay
    TCCR1B = 0;
  }
}