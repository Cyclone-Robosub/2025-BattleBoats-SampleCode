#include "ultrasonic.h"

void ultrasonicInit() {
  // configure ultrasonic pins
  pinMode(TRIG_PINFRONT, OUTPUT);
  pinMode(ECHO_PINFRONT, INPUT);
  pinMode(TRIG_PINSIDE, OUTPUT);
  pinMode(ECHO_PINSIDE, INPUT);
}

float readFrontDistCM() {
  // Set TRIG low 
  digitalWrite(TRIG_PINFRONT, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PINFRONT, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINFRONT, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PINFRONT, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}

float readSideDistCM(){
    // Set TRIG low 
  digitalWrite(TRIG_PINSIDE, LOW);
  delayMicroseconds(2);
  // Pulse TRIG for 10 microseconds 
  digitalWrite(TRIG_PINSIDE, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PINSIDE, LOW);

  // Measure microseconds taken for sound to send and bounce back
  long duration_us = pulseIn(ECHO_PINSIDE, HIGH);

  // distance = time * speed of sound
  // speed of sound in cm / uS = 0.0343
  float distance = (duration_us * 0.0343) / 2.0;
  return distance;
}
