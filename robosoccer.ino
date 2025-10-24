
#include "BluetoothSerial.h"   // ESP32 Bluetooth library
BluetoothSerial SerialBT;
// Motor driver pins (L298N)
const int IN1 = 27;
const int IN2 = 26;
const int IN3 = 25;
const int IN4 = 33;
char command;  // stores received command
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_RC_Car");   // Bluetooth device name
  // Motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopCar();  // start stopped
  Serial.println("RC Car ready! Connect via Bluetooth.");
}
void loop() {
  if (SerialBT.available()) {
    command = SerialBT.read();  // read command
    Serial.print("Received: ");
    Serial.println(command);
    switch (command) {
      case 'F': forward(); break;      // Forward
      case 'B': backward(); break;     // Backward
      case 'L': left(); break;         // Left
      case 'R': right(); break;        // Right
      case 'G': forwardLeft(); break;  // Forward Left
      case 'I': forwardRight(); break; // Forward Right
      case 'H': backwardLeft(); break; // Backward Left
      case 'J': backwardRight(); break;// Backward Right
      case 'S': stopCar(); break;      // Stop
    }
  }
}
// ===== Motor Functions =====
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void forwardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void forwardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void backwardLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void backwardRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}