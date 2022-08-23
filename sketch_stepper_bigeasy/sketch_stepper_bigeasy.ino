// Pins to use
const int  STEP = 2; // step the motor
const int  DIR = 3;  // set the motor direction
const int  MS1 = 4;  // select microstepping mode
const int  MS2 = 5;  // select microstepping mode
const int  MS3 = 6;  // select microstepping mode
const int  EN  = 7;  // enable / disable stepper

// Store the current direction (forward=LOW, backward=HIGH)
int currentDir = LOW;

void setup() {
  Serial.begin(9600);
  
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(EN, OUTPUT);
  
  //Set all pins to default states
  resetEDPins(); 
}

void loop() {
  char user_input;

  // Read user input
  while(Serial.available()){
      user_input = Serial.read(); 

      // Enable the motor driver
      digitalWrite(EN, LOW);

      // Decode and execute user instruction
      if (user_input == 's')
        DefaultStep();
      else if(user_input == '1')
        FullStep();
      else if(user_input == '2')
        HalfStep();     
      else if(user_input == '4')
        QuarterStep();     
      else if(user_input == '8')
        EighthStep();     
      else if(user_input == '6')
        SixteenthStep();
      else if(user_input == 'd')
        FlipDirection();
      else
        Serial.println("Invalid option entered:");

      // Reset all pins back to default state
      resetEDPins();
  }
}

// Move stepper
//  steps - number of steps to move
//  delayus - delay between pin transitions.  Higher means slower movement.
void MoveSteps(int steps, int delayus)
{
  for(int s=0; s<steps; s++)  
  {
    // Motor steps when STEP pin transitions from LOW to HIGH
    digitalWrite(STEP, HIGH);   // one step forward
    delayMicroseconds(delayus); // wait a bit
    digitalWrite(STEP, LOW);    // reset pin 
    delayMicroseconds(delayus); // wait a bit
  }
}

// Move the stepper using the default stepping mode.  Does not require the microstepping (MS) pins
void DefaultStep()
{
  Serial.println("Moving at default step mode.");
  digitalWrite(DIR, currentDir); 
  MoveSteps(1000, 1000);
}

// Move the stepper in full steps
void FullStep()
{
  Serial.println("Stepping at full step mode.");
  digitalWrite(DIR, currentDir); 
  digitalWrite(MS1, LOW); 
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  
  MoveSteps(1000, 1000);
}

// Move the stepper in half steps
void HalfStep()
{
  Serial.println("Stepping at full half mode.");
  digitalWrite(DIR, currentDir); 
  digitalWrite(MS1, HIGH); 
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);  

  MoveSteps(1000, 1000);
}

// Move the stepper in quarter steps
void QuarterStep()
{
  Serial.println("Stepping at quarter step mode.");
  digitalWrite(DIR, currentDir); 
  digitalWrite(MS1, LOW); 
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);  

  MoveSteps(1000, 1000);
}

// Move the stepper in eigth steps
void EighthStep()
{
  Serial.println("Stepping at eigth step mode.");
  digitalWrite(DIR, currentDir); 
  digitalWrite(MS1, HIGH); 
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, LOW);

  MoveSteps(1000, 1000);
}

// Move the stepper in sixteenth steps
void SixteenthStep()
{
  Serial.println("Stepping at sixteenth step mode.");
  digitalWrite(DIR, currentDir); 
  digitalWrite(MS1, HIGH); 
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);  

  MoveSteps(1000, 1000);
}

// Change the motor direction
void FlipDirection()
{
  if (currentDir == LOW)
    currentDir = HIGH;
  else
    currentDir = LOW;
}

// Reset all pins to default states
void resetEDPins()
{
  digitalWrite(STEP, LOW);
  digitalWrite(DIR, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  digitalWrite(EN, HIGH);
}
