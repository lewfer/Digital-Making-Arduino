int TMP36 = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                   //the resolution is 10 mV / degree centigrade with a
                   //500 mV offset to allow for negative temperatures
 
void setup()
{
  Serial.begin(9600);
}
 
void loop() 
{
  // Get the reading from the temperature sensor (0 to 1023)
  int reading = analogRead(TMP36);  
 
  // Convert the reading to a voltage (for 3.3v Arduinos use 3.3 instead of 5.0)
  float voltage = reading * 5.0;
  voltage /= 1024.0; 
 
  // Print out the voltage
  Serial.print(voltage); Serial.println(" volts");
 
  // Convert to a temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                                //to degrees ((voltage - 500mV) times 100)

  // Print out the temperature
  Serial.print(temperatureC); Serial.println(" degrees C");
 
  delay(1000); 
}
