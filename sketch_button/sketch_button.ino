// Constants
const int LED = 13;
const int BUTTON = 7;

// Variables
int val = 0;
int old_val = 0;
int state = 0; // 0=off, 1=on

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);

  // Check if the button is changing from not pressed to pressed
  if ((val==HIGH) && (old_val==LOW))
  {
    state = 1 - state;        // flip the button state 1->0 or 0->1
    delay(10);                // debounce, to prevent multiple quick button presses
  }

  // Remember the old button state
  old_val = val;

  // Set the LED according to the button state
  if (state == 1)
    digitalWrite(LED,HIGH);
  else
    digitalWrite(LED,LOW);
}
