#define BTN1 6 // PD6 → PCINT22
#define BTN2 7 // PD7 → PCINT23
#define LED1 2 // PD2
#define LED2 3 // PD3

volatile bool led1_state = false;
volatile bool led2_state = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);

  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B = 0b00000100; // prescaler 256
  TIMSK1 = 0b00000010; // enable Timer1 Compare A interrupt
  OCR1A = 31250;
  sei();
}

void loop() {
}

ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0;
  bool btn1 = digitalRead(BTN1);
  bool btn2 = digitalRead(BTN2);

  // Button pressed when LOW
  if (btn1 == LOW) {
    led1_state = !led1_state;
    digitalWrite(LED1, led1_state);
  }
  if (btn2 == LOW) {
    led2_state = !led2_state;
    digitalWrite(LED2, led2_state);
  }
}