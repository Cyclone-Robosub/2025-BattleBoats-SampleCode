#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================

#define TRIG_PINFRONT 2
#define ECHO_PINFRONT 3
#define TRIG_PINSIDE 8
#define ECHO_PINSIDE 9
//there I define the interface of the sensor from the front

void ultrasonicInit();
float readDistanceCM();
float readDistanceCM2();

#endif
