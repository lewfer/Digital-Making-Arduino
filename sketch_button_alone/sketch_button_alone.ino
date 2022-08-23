// Constants
const int BUTTONPIN = 7;

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  int but = LOW;                  // state of the button (HIGH=pressed, LOW=not pressed)

  // Read the value from the button
  but = digitalRead(BUTTONPIN);

  // Check if button is changing from off to on
  if (but==HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
