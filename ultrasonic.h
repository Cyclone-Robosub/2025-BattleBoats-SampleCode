#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ==============================
//       Pin configuration
// ==============================
#define TRIG_PIN 2
#define ECHO_PIN 3

// for the second sensor

#define TRIG2_PIN 8
#define ECHO2_PIN 9

void ultrasonicInit();
float readDistanceCM();

#endif
