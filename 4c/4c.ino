#define PINP PB2   // PORTB bit 2
#define PINR PB2   // same pin

volatile bool state = false;

void setup() {
  DDRD &= ~(1 << PD2);   // PD2 as input for INT0
  PORTD |= (1 << PD2);   // enable pull-up on PD2

  DDRB |= (1 << PINP);   // PB2 as output for both LEDs

  EICRA |= (1 << ISC01); // INT0 falling edge
  EIMSK |= (1 << INT0);  // enable INT0
  sei();                 // enable global interrupts
}

ISR(INT0_vect) {
  state = !state;
  if (state) {
    PORTB |= (1 << PINP);   // PB2 HIGH → both LEDs ON
  } else {
    PORTB &= ~(1 << PINP);  // PB2 LOW → both LEDs OFF
  }
}

void loop() {
  // nothing, all in ISR
}