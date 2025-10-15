#include "motors.h"
#include "ultrasonic.h"

/* Global Constants */
#define FRONT_SENSOR = 0 // FINISH REST OF DEFINITIONS
const int SIDE_SENSOR = 1;
const int regDelayTimeMS = 100; // PLACEHOLDER
const int turnDelayTimeMS = 50; // PLACEHOLDER
const int turnSpeedRPM = 70; // 0 - 255, should be in 70-90 range
const int forwardSpeedRPM = 90; // 0 - 255, should be in 70-90 range
const int minFrontDistance = 100; // PLACEHOLDER
const int minRightDistance = 50; // PLACEHOLDER


/* Function Declarations */
float avgSensorReadingMethod1(int sensor);
float avgSensorReadingMethod2(int sensor);
bool checkIfTurn(float currFrontDist);
bool checkIfRightTurn(float currSideDist);

/*
Parameters for Sensor Readings Method 1 (SRM1)
TO BE DELETED IF SRM1 NOT USED
*/
int INDEX = 0;
int WINDOW_SIZE = 10; //ADJUST WINDOW TO SEE IF MORE ACCURATE
float VALUE = 0;
float SUM = 0;
float READINGS[WINDOW_SIZE];
float AVERAGED = 0;

/*
Parameters for Sensor Readings Method 2 (SRM2)
TO BE DELETED IF SRM2 NOT USED
*/
int numReadings = 10; //ADJUST WINDOW TO SEE IF MORE ACCURATE
float readings[numReadings]; 
int index = 0; 
float total = 0; 
float average = 0; 


void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

void loop(){
  float currFrontDist = avgSensorReadingMethod1(FRONT_SENSOR);
  Serial.println(currFrontDist);

  // float currSideDist = avgSensorReadingMethod1(SIDE_SENSOR);
  // Serial.println(currFrontDist);

  delay(regDelayTimeMS);
}

// void loop() {
//   float currFrontDist = avgSensorReadingMethod1(FRONT_SENSOR);
//   float currSideDist = avgSensorReadingMethod1(SIDE_SENSOR);

//   //EDIT: isTurning -> shouldTurn
//   bool isTurning = checkIfTurn(currFrontDist);
//   bool rightTurn;

//   if(isTurning){
//     rightTurn = checkIfRightTurn(currSideDist);

//     if(rightTurn) turnRight(turnSpeedRPM);
//     else turnLeft(turnSpeedRPM);

//     delay(turnDelayTimeMS); // ASK!! about automizing turning, having set time good enough method?
//   }

//   driveForward(forwardSpeedRPM);
  
//   delay(regDelayTimeMS);
// }

/*
Parameters: current distance from front sensor
Description: check if turning conditions have been met
Explanation: ie. if K.C is about to run into a wall
*/ 
bool checkIfTurn(float currFrontDist){
  return currFrontDist <= minFrontDistance;
}

/*
Parameters: current distance from side sensor
Description: check if turning left or right
Explanation: ie. if K.C's right side is a wall or not
*/
bool checkIfRightTurn(float currSideDist){
  return currSideDist > minRightDistance;
}

/*
Description: Moving average filter code 
Source: (https://maker.pro/arduino/tutorial/how-to-clean-up-noisy-sensor-data-with-a-moving-average-filter),
Considerations: Larger window size would make the data flatter BUT could cause signal lag and infomation loss
Other: IF SELECTED, TO BE RENAMED TO: avgSensorDist(int sensor)
*/
float avgSensorReadingMethod1(int sensor){
  SUM = SUM - READINGS[INDEX];       // Remove the oldest entry from the sum
  if(sensor == FRONT_SENSOR) VALUE ? readFrontDistCM(): readSideDistCM(); // Read the next sensor value
  READINGS[INDEX] = VALUE;           // Add the newest reading to the window
  SUM = SUM + VALUE;                 // Add the newest reading to the sum
  INDEX = (INDEX+1) % WINDOW_SIZE;   // Increment the index, and wrap to 0 if it exceeds the window size

  AVERAGED = SUM / WINDOW_SIZE; 

  return AVERAGED;
}

/*
Description: another moving average filter 
Source: (https://energia.nu/guide/tutorials/analog/tutorial_smoothing/)
Considerations: Essentially same method as last, just better readability
Other: IF SELECTED, TO BE RENAMED TO: avgSensorDist(int sensor)
*/
float avgSensorReadingMethod2(int sensor){
  total = total - readings[index];
  if(sensor == FRONT_SENSOR) readings[index] ? readFrontDistCM(): readSideDistCM();
  total = total + readings[index];
  index = index + 1;

  if (index >= numReadings) index = 0; // if at the end of the array, wrap to beginning

  average = total / numReadings;

  return average;
}