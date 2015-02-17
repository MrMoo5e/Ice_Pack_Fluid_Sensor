
// declares global variables below
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensOutput = 7;
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
void setup() {
  // set pins as inputs and outputs:
  pinMode(ledPin, OUTPUT);
  pinMode(sensOutput, OUTPUT);
  Serial.begin(9600); 
}



void loop() {
  sensorValue = analogRead(sensorPin);   // read the inital value from the sensor
  delay(5);
  sensorValue2 = analogRead(sensorPin);  // reads a second value from the sensor after the above delay
  delay(5);
  sensorValue3 = analogRead(sensorPin);  //reads a 3rd value from the sensor after the above delay
  float SensorAvg = 0;
  float SensorSum = 0;
  int SensorInst = 0;
  SensorSum = sensorValue + sensorValue2 + sensorValue3; // takes the sum of the 3 sensor readings
  SensorAvg = SensorSum/3;  // divides by 3 to get the average
  Serial.println(sensorValue, DEC); // Writes the sensorValue in DEC to the terminal 
  delay(10);
  Serial.println(SensorAvg, DEC);  // writes the average value to the teminal in decimal
  delay(10);
  //Reads the sensor value to compare to the average
  sensorValue4 = analogRead(sensorPin);
  //subtracts the threshold of change from the sensor value
  SensorInst = sensorValue4 - 5;
  if(SensorInst > SensorAvg) {
    digitalWrite(sensOutput, LOW);
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
  // sets a threshold that ignores the averaging incase the board gets flooded 
  if (SensorInst > 700){
    digitalWrite(sensOutput, LOW);  //controls the pin to the relay. Because the relay is NC this actually puts 24v to the output
    digitalWrite(ledPin, HIGH);  // turns on the on board LED
    delay(50); 
  }
  else {
    digitalWrite(sensOutput, HIGH);  // Stops voltage from flowing throught the relay
    digitalWrite(ledPin, LOW);  // turns the led off
    delay(10); 
  }    
  
}
