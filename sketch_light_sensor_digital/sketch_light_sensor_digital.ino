// Constants
const int LED = 9;
const int BUTTON = 7;

// Variables
int but = 0;        // state of the button (1=pressed, 0=not pressed)
int old_but = 0;    // previous button state
int state = 0;      // 0=off, 1=on

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // Read the value from the button
  but = digitalRead(BUTTON);
  
  // Check if button is changing from off to on
  if ((but==HIGH) && (old_but==LOW))
  {
    state = 1 - state;
    delay(10); // debounce
  }
  
  // Remember the old button state
  old_but = but;

  // Set the LED according to the button state
  if (state == 1)
    digitalWrite(LED,HIGH);
  else
    digitalWrite(LED,LOW);
}
