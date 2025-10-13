#include "motors.h"
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

void loop() {
  float dist = readDistanceCM();
  float dist2 = readDistanceCM2();
  
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");|
  
  Serial.println("Distance: ";
  Serial.print(dist2);
  Serial.print(" cm");

  if (dist > 15) {
    driveForward(150);
  } else {
    driveStop();
  }

  delay(100);
}
/*moving average filter code(https://maker.pro/arduino/tutorial/how-to-clean-up-noisy-sensor-data-with-a-moving-average-filter),
//Larger window size would make the data flatter BUT could cause signal lag and infomation loss
#define IN_PIN A0
#define WINDOW_SIZE 5

int INDEX = 0;
int VALUE = 0;
int SUM = 0;
int READINGS[WINDOW_SIZE];
int AVERAGED = 0;

void setup() {
  pinMode(IN_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  SUM = SUM - READINGS[INDEX];       // Remove the oldest entry from the sum
  VALUE = analogRead(IN_PIN);        // Read the next sensor value
  READINGS[INDEX] = VALUE;           // Add the newest reading to the window
  SUM = SUM + VALUE;                 // Add the newest reading to the sum
  INDEX = (INDEX+1) % WINDOW_SIZE;   // Increment the index, and wrap to 0 if it exceeds the window size

  AVERAGED = SUM / WINDOW_SIZE;      // Divide the sum of the window by the window size for the result

  Serial.print(VALUE);
  Serial.print(",");
  Serial.println(AVERAGED);
*/
/*another moving average filter (https://energia.nu/guide/tutorials/analog/tutorial_smoothing/)
const int numReadings = 10;

int readings[numReadings]; // the readings from the analog input
int index = 0; // the index of the current reading
int total = 0; // the running total
int average = 0; // the average

int inputPin = A3;

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
}

void loop() {
  // subtract the last reading:
  total= total - readings[index];
  // read from the sensor:
  readings[index] = analogRead(inputPin);//analogRead(inputPin)Reads the value from a specified analog input pin
  // add the reading to the total:
  total= total + readings[index];
  // advance to the next position in the array:
  index = index + 1;

  // if we're at the end of the array...
  if (index >= numReadings)
    // ...wrap around to the beginning:
    index = 0;

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
  delay(1); // delay in between reads for stability
}*/
