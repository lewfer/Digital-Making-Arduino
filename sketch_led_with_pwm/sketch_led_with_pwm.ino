// Constants
const int LED = 9;

// Variables
int i = 0;

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Turn brightness up gradually
  for (i=0; i<255; i++) {
    analogWrite(LED, i);      // set the brightness level
    delay(10);                // wait a bit to slow down the transition
  }

  // Turn brightness down gradually
  for (i=255; i>0; i--) {
    analogWrite(LED, i);      // set the brightness level
    delay(10);                // wait a bit to slow down the transition
  }
}
