// Constants
const int BUTTONPIN = 7;

// Global variables
int state = LOW;
int lastState = LOW;
int lastToggleTime = 0;
int debounceWaitTime = 50;
  
void setup() {
  // Tell Arduino which pins are input and output
  pinMode(BUTTONPIN, INPUT);
}

void loop() {
  int but = LOW;                  // state of the button (HIGH=pressed, LOW=not pressed)

  // Read the value from the button
  but = digitalRead(BUTTONPIN);

  if (but != lastState)
    lastToggleTime = millis();

  if ((millis() - lastToggleTime) > debounceWaitTime)
  {
    if (but != state)
    {
      state = but;

      // If the button is pressed, flip the state
      if (state==HIGH) 
        state = 1 - state;     
    }
  }

  // Switch the LED on depending on the state
  if (state==HIGH)
    digitalWrite(LED_BUILTIN, HIGH);    
  else
    digitalWrite(LED_BUILTIN, LOW);

  lastState = state;
}
