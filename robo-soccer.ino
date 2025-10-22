#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

// ====== IBT-2 Motor Driver Pins ======
// Left motor driver
#define L_LPWM 26   // Left motor LPWM
#define L_RPWM 27   // Left motor RPWM
// Right motor driver
#define R_LPWM 25   // Right motor LPWM
#define R_RPWM 33   // Right motor RPWM

// ====== Control variables ======
char command;
int motorSpeed = 200;   // (0–255) adjust as needed

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_IBT2_RCcar");
  Serial.println("IBT-2 Dual Driver RC Car Ready!");

  pinMode(L_LPWM, OUTPUT);
  pinMode(L_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);
  pinMode(R_RPWM, OUTPUT);

  stopCar();
}

// ====== LOOP ======
void loop() {
  if (SerialBT.available()) {
    command = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(command);

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'G': forwardLeft(); break;
      case 'I': forwardRight(); break;
      case 'H': backwardLeft(); break;
      case 'J': backwardRight(); break;
      case 'S': stopCar(); break;
    }
  }
}

// ====== MOTOR CONTROL FUNCTIONS ======
void forward() {
  analogWrite(L_RPWM, motorSpeed);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, motorSpeed);
  analogWrite(R_LPWM, 0);
}

void backward() {
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, motorSpeed);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, motorSpeed);
}

void left() {
  // left side backward, right side forward (pivot turn)
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, motorSpeed);
  analogWrite(R_RPWM, motorSpeed);
  analogWrite(R_LPWM, 0);
}

void right() {
  // right side backward, left side forward (pivot turn)
  analogWrite(L_RPWM, motorSpeed);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, motorSpeed);
}

void forwardLeft() {
  // left slower, right full
  analogWrite(L_RPWM, motorSpeed / 2);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, motorSpeed);
  analogWrite(R_LPWM, 0);
}

void forwardRight() {
  // right slower, left full
  analogWrite(L_RPWM, motorSpeed);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, motorSpeed / 2);
  analogWrite(R_LPWM, 0);
}

void backwardLeft() {
  // left slower reverse, right full reverse
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, motorSpeed / 2);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, motorSpeed);
}

void backwardRight() {
  // right slower reverse, left full reverse
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, motorSpeed);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, motorSpeed / 2);
}

void stopCar() {
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 0);
}
