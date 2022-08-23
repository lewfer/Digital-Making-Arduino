// Constants

// Motor A pins
const int FWDA = 7;
const int BWDA = 6;
const int SPEEDA = 10;

// Motor B pins
const int FWDB = 5;
const int BWDB = 4;
const int SPEEDB = 9;

void setup() {
  pinMode(FWDA, OUTPUT);
  pinMode(BWDA, OUTPUT);
  pinMode(SPEEDA, OUTPUT);
  pinMode(FWDB, OUTPUT);
  pinMode(BWDB, OUTPUT);
  pinMode(SPEEDB, OUTPUT);
}

void loop() {
  // Slowly increase the forward speed of motor A
  for (int s=0; s<=100; s+=10) {
    turnMotorAForward(s);
    delay(1000);
  }
  stopMotorA();

  
  // Slowly increase the backward speed of motor A
  for (int s=0; s<=100; s+=10) {
    turnMotorABackward(s);
    delay(1000);
  }
  stopMotorA();

  // Slowly increase the forward speed of motor B
  for (int s=0; s<=100; s+=10) {
    turnMotorBForward(s);
    delay(1000);
  }
  stopMotorB();
  
  // Slowly increase the backward speed of motor B
  for (int s=0; s<=100; s+=10) {
    turnMotorBBackward(s);
    delay(1000);
  }
  stopMotorB();  
}

// Turn motor A forwards at speed s (from 0 to 100)
void turnMotorAForward(int s){              
  digitalWrite(FWDA, HIGH);
  digitalWrite(BWDA, LOW);  
  analogWrite(SPEEDA, s*255/100);
}

// Turn motor A backwards at speed s (from 0 to 100)
void turnMotorABackward(int s){
  digitalWrite(FWDA,LOW);
  digitalWrite(BWDA,HIGH);
  analogWrite(SPEEDA, s*255/100);
}

// Stop motor A
void stopMotorA(){
  digitalWrite(FWDA, LOW);
  digitalWrite(BWDA, LOW);
}

// Turn motor B forwards at speed s (from 0 to 100)
void turnMotorBForward(int s){              
  digitalWrite(FWDB, HIGH);
  digitalWrite(BWDB, LOW); 
  analogWrite(SPEEDB, s*255/100);
}

// Turn motor B backwards at speed s (from 0 to 100)
void turnMotorBBackward(int s){
  digitalWrite(FWDB, LOW);
  digitalWrite(BWDB, HIGH);
  analogWrite(SPEEDB, s*255/100);
}

// Stop motor B
void stopMotorB(){
  digitalWrite(FWDB, LOW);
  digitalWrite(BWDB, LOW);
}
