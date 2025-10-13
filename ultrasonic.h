#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PINFRONT 2
#define ECHO_PINFRONT 3
//there I define the interface of the sensor from the front
void ultrasonicInit();
float readDistanceCM();

#endif
