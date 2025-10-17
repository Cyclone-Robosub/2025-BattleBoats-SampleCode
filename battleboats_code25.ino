#include "motors.h"
#include "ultrasonic.h"

/* Global Constants */
#define FRONT_SENSOR 0 // FINISH REST OF DEFINITIONS
#define SIDE_SENSOR 1
#define regDelayTimeMS 100 // PLACEHOLDER
#define turnDelayTimeMS 5 // PLACEHOLDER
#define turnSpeedRPM 70 // 0 - 255, should cnabe in 70-90 range
#define forwardSpeedRPM 90 // 0 - 255, should be in 70-90 range
#define minFrontDistance 100 // PLACEHOLDER
#define minRightDistance 50 // PLACEHOLDER
#define numReadings 10 //ADJUST WINDOW TO SEE IF MORE ACCURATE

//Parameters for Sensor Readings Method 
float readings[numReadings]; 
int index = 0; 
float total = 0; 
float average = 0; 

/* Function Declarations */
float avgSensorReadingMethod1(int sensor);
float avgSensorDist(int sensor);
bool checkIfTurn(float currFrontDist);
bool checkIfRightTurn(float currSideDist);

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

// void loop(){
//   float currFrontDist = avgSensorDist(FRONT_SENSOR);
//   Serial.println(currFrontDist);

//   // float currSideDist = avgSensorReadingMethod1(SIDE_SENSOR);
//   // Serial.println(currFrontDist);

//   delay(regDelayTimeMS);
// }

void loop() { 
  float currFrontDist = avgSensorDist(FRONT_SENSOR);
  float currSideDist = avgSensorDist(SIDE_SENSOR);

  bool shouldTurn = checkIfTurn(currFrontDist);
  bool rightTurn;

  if(shouldTurn){
    rightTurn = checkIfRightTurn(currSideDist);

    if(rightTurn) turnRight(turnSpeedRPM);
    else turnLeft(turnSpeedRPM);

    delay(turnDelayTimeMS); 
  }

  driveForward(forwardSpeedRPM);
  
  delay(regDelayTimeMS);
}

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
Description: another moving average filter 
Source: (https://energia.nu/guide/tutorials/analog/tutorial_smoothing/)
Considerations: Essentially same method as last, just better readability
Other: IF SELECTED, TO BE RENAMED TO: avgSensorDist(int sensor)
*/
float avgSensorDist(int sensor){
  total = total - readings[index];
  if(sensor == FRONT_SENSOR) readings[index] ? readFrontDistCM(): readSideDistCM();
  total = total + readings[index];
  index = index + 1;

  if (index >= numReadings) index = 0; // if at the end of the array, wrap to beginning

  average = total / numReadings;

  return average;
}