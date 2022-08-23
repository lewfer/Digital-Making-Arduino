// Constants

// Motor pins
const int MOTORPIN1 = 7;
const int MOTORPIN2 = 6;
const int MOTORPIN3 = 5;

int count = 0;
int wait = 5; // milliseconds
bool bwd = false;

void setup() {
  pinMode(MOTORPIN1, OUTPUT);
  pinMode(MOTORPIN2, OUTPUT);
  pinMode(MOTORPIN3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  /*if (count>300)
    wait = 2;
  else if (count>200)
    wait = 3;
  else if (count>100)
    wait = 4;
    */

   bwd = (count/100 % 2);

  //Serial.println(wait);

  if (bwd) {
    Serial.println("bwd");
    digitalWrite(MOTORPIN3, 1);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN1, 0);
    delay(wait);
    digitalWrite(MOTORPIN3, 1);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN1, 0);
    delay(wait);
    digitalWrite(MOTORPIN3, 1);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN1, 1);
    delay(wait);
    digitalWrite(MOTORPIN3, 0);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN1, 1);
    delay(wait);
    digitalWrite(MOTORPIN3, 0);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN1, 1);
    delay(wait);
    digitalWrite(MOTORPIN3, 0);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN1, 0);
    delay(wait);
    }
  else
    {
    Serial.println("fwd");
    digitalWrite(MOTORPIN1, 1);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN3, 0);
    delay(wait);
    digitalWrite(MOTORPIN1, 1);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN3, 0);
    delay(wait);
    digitalWrite(MOTORPIN1, 1);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN3, 1);
    delay(wait);
    digitalWrite(MOTORPIN1, 0);
    digitalWrite(MOTORPIN2, 0);
    digitalWrite(MOTORPIN3, 1);
    delay(wait);
    digitalWrite(MOTORPIN1, 0);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN3, 1);
    delay(wait);
    digitalWrite(MOTORPIN1, 0);
    digitalWrite(MOTORPIN2, 1);
    digitalWrite(MOTORPIN3, 0);
    delay(wait);
  }

  count++;
}
