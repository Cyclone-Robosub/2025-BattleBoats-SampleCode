#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PIN 3
#define ECHO_PIN 2

void ultrasonicInit();
float readDistanceCM();

#endif
