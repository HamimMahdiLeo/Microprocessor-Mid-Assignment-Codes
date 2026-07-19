const byte switchPin = 2;
const byte greenLED = 6;
const byte redLED = 7;

bool lastSwitchState = HIGH;
bool systemState = 0;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}

void loop() {
  bool reading = digitalRead(switchPin);

  if (reading == LOW && lastSwitchState == HIGH) {
    systemState = !systemState; // Toggle state

    if (systemState == 0) {
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
    } 
    else {
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
    }
  }

  lastSwitchState = reading;
}