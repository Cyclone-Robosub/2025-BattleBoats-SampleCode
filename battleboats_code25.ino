#include "motors.h"
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);
  motorInit();
  ultrasonicInit();
}

void loop() {
  float dist = readDistanceCM();
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  if (dist > 15) {
    driveForward(150);
  } else {
    driveStop();
  }

  delay(100);
}
