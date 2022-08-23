// Includes
#include <Servo.h>

// Objects
Servo servo[4];       // array of 4 servos

void setup() {
  // Attach all servo objects to pins
  servo[0].attach(5);
  servo[1].attach(4);
  servo[2].attach(3);
  servo[3].attach(2);
}

void loop() {
  // Move all to 180 degrees
  for (int i=0; i<4; i++) 
    servo[i].write(180);
    
  delay(1000);
  
  // Move all to 90 degrees
  for (int i=0; i<4; i++) 
    servo[i].write(90);

  delay(1000);

  // Move all to 0 degrees
  for (int i=0; i<4; i++)     
    servo[i].write(0);
    
  delay(1000);
}
