// Constants
const int POT = A2;

void setup() {
  // Tell Arduino which pins are input and output
  pinMode(POT, INPUT); 

  // Start the serial communications
  Serial.begin(9600);
}

void loop() {
  // Read the value from the potentiometer
  int val = analogRead(POT);    

  // Write value to serial debugger
  Serial.println(val);
  delay(100);
}
