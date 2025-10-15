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

void ultrasonicInit();
float readFrontDistCM();
float readSideDistCM();

#endif
