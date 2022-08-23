const int TRIGGER = 7;                  // Trigger Pin of Ultrasonic Sensor
const int ECHO = 6;                     // Echo Pin of Ultrasonic Sensor
const long SPEED_OF_SOUND = 34300L;     // centimetres per second 

void setup() {
   Serial.begin(9600); 
   
   pinMode(ECHO, INPUT);
}

void loop() {
   long duration, cm;
   long cm_per_microsecond = 1000000L / SPEED_OF_SOUND;

   // Send a 10us pulse on the trigger pin to initiate the sensor
   pinMode(TRIGGER, OUTPUT);
   digitalWrite(TRIGGER, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIGGER, HIGH);
   delayMicroseconds(10);
   digitalWrite(TRIGGER, LOW);

   // Wait for the echo pin to go low, start timing, then wait for pin to go high
   // See https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
   // Get the duration in microseconds
   duration = pulseIn(ECHO, HIGH);

   // Compute the duration in cm
   cm = duration / cm_per_microsecond / 2;

   // Print result to serial port
   Serial.print(cm);   
   Serial.print("cm");
   Serial.println();
   
   delay(100);
}
