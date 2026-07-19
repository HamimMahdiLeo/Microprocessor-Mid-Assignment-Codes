#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);

  cli();
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // CTC mode, prescaler 1024
  OCR1A = 9031; // for 578ms
  TIMSK1 = (1 << OCIE1A); // enable compare match interrupt
  TCNT1 = 0;
  sei();
}

ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // toggle every 578ms
}

void loop() {
  // main loop unused; toggling handled by ISR
}