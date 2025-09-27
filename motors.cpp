#include "motors.h"

// ==============================
//             Setup
// ==============================
void motorInit() {
  // configure motor pins
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(IN3_PIN, OUTPUT);
  pinMode(IN4_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  driveStop();
}

// ==============================
//         Motor control
// ==============================
void driveForward(int speed) {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);

  analogWrite(ENA_PIN, speed);
  analogWrite(ENB_PIN, speed);
}

void driveBackward(int speed) {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);

  analogWrite(ENA_PIN, speed);
  analogWrite(ENB_PIN, speed);
}

void turnLeft(int speed) {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, HIGH);
  digitalWrite(IN3_PIN, HIGH);
  digitalWrite(IN4_PIN, LOW);

  analogWrite(ENA_PIN, speed);
  analogWrite(ENB_PIN, speed);
}

void turnRight(int speed) {
  digitalWrite(IN1_PIN, HIGH);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, HIGH);

  analogWrite(ENA_PIN, speed);
  analogWrite(ENB_PIN, speed);
}

void driveStop() {
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
  digitalWrite(IN3_PIN, LOW);
  digitalWrite(IN4_PIN, LOW);

  analogWrite(ENA_PIN, 0);
  analogWrite(ENB_PIN, 0);
}
