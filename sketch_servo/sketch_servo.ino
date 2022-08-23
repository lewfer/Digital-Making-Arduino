// Includes
#include <Servo.h>

// Constants
const int SERVO = 9;

// Objects
Servo myservo;

void setup() {
  // Attach the servo object to the servo pin
  myservo.attach(SERVO);
}

void loop() {
  // Move the servo through its full range
  myservo.write(180);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(1000);
}
