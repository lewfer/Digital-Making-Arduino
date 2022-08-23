#include <Wire.h>
#include "Adafruit_TCS34725.h"

#define POWERPIN   4

/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */

/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

// our RGB -> eye-recognized gamma color
byte gammatable[256];


void setup(void) {
  Serial.begin(115200);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  pinMode(POWERPIN, OUTPUT);

  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    gammatable[i] = x;
    Serial.println(gammatable[i]);
  }

  
  // Now we're ready to get readings!
}

void loop(void) {
  float red, green, blue;

  digitalWrite(POWERPIN,HIGH);

  tcs.getRGB(&red, &green, &blue);
  
  Serial.print("R: "); Serial.print(gammatable[(int)red]); Serial.print(" ");
  Serial.print("G: "); Serial.print(gammatable[(int)green]); Serial.print(" ");
  Serial.print("B: "); Serial.print(gammatable[(int)blue]); Serial.print(" ");
  Serial.println(" ");
  
  digitalWrite(POWERPIN,LOW);
  delay(500);
}
