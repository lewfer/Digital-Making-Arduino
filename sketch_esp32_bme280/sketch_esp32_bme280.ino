// Include libraries
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>

// Your wifi details
const char* ssid = "ThinkCreateLearn";
const char* password = "curiousgecko";

// Your MQTT Broker IP address
const char* mqtt_broker = "192.168.2.141";

// Create a wifi client
WiFiClient wifiClient;

// Create a MQTT client
PubSubClient mqttClient(wifiClient);


long lastMsgTime = 0;    // keep track of when we sent the last message
//char msg[50];
//int value = 0;

// Create a weather sensor object
Adafruit_BME280 bme; // I2C
float temperature = 0;
float humidity = 0;

// LED Pin
const int ledPin = 4;

void setup() {
  // Set up the serial port communications, for debugging
  Serial.begin(115200);
  
  // Check for a BME280 sensor on the given I2C address
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Connect to wifi
  setup_wifi();

  // Set up MQTT broker
  mqttClient.setServer(mqtt_broker, 1883);

  pinMode(ledPin, OUTPUT);
}

void setup_wifi() {
  delay(10);
  
  // Connect to wifi network
  Serial.print("\nConnecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // Wait for successful wifi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Display connection info
  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnectMQTT() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT reconnection...");
    // Attempt to connect
    if (mqttClient.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      mqttClient.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop() {
  // Re-establish MQTT connection if dropped
  if (!mqttClient.connected()) {
    reconnectMQTT();
  }

  // Process incoming MQTT messages and keep connection to broker
  mqttClient.loop();

  // Wait 5 seconds between readings
  long now = millis();
  if (now - lastMsgTime > 5000) {
    lastMsgTime = now;
    
    // Read the temperature in Celsius
    temperature = bme.readTemperature();   
    
    // Convert the value to a char array
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);

    // Publish the temperature over MQTT
    mqttClient.publish("esp32/temperature", tempString);

    // Read the humidity
    humidity = bme.readHumidity();
    
    // Convert the value to a char array
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);

    // Publish the temperature over MQTT
    mqttClient.publish("esp32/humidity", humString);
  }
}
