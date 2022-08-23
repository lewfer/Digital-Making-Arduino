// Constants
const int LED = 9;

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Flash the LED
  digitalWrite(LED,HIGH);
  delay(1000);
  digitalWrite(LED,LOW);
  delay(1000);
}
