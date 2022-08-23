// Constants
const int LED = 9;
const int BUTTON = 7;

// Variables
int but = 0;                  // state of the button (1=pressed, 0=not pressed)
int brightness = 128;         // current led brightness

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  // Read the value from the button
  but = digitalRead(BUTTON);

  // Check if button is changing from off to on
  if (but==HIGH)
  {
      brightness+= 5;         // turn the brightness up a bit
      delay(30);              // dely to slow down the transition
      if (brightness>255)     // if we reach maximum brightness, go back to 0
        brightness = 0;
  }

  // Set the LED brightness
  analogWrite(LED, brightness);
}
