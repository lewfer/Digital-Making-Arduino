#include <WiFiNINA.h>

#define WIFI_SSID "ThinkCreateLearn"
#define WIFI_PASSWORD "curiousgecko"


void setup() {
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  
  //Initialize serial and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  int status = WL_IDLE_STATUS;
  
  // check for the WiFi module:
  while (status != WL_CONNECTED)
  {
    status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(".");
    delay(300);
  }
  Serial.print("Connected");
  Serial.println(WiFi.localIP());

  
}

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
