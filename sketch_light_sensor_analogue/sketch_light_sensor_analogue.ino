// Constants
const int LED = 9;
const int LDR = A0;

// Variables
int val = 0;        // reading from the LDR

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT); 
}

void loop() {
  // Read the value from the LDR
  val = analogRead(LDR);

  // Flash the LED, using the LDR value as the delay
  digitalWrite(LED,HIGH);
  delay(val);
  digitalWrite(LED,LOW);
  delay(val);
}
