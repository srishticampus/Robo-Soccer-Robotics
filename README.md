# 🤖 RoboSoker - Bluetooth Controlled Robot Car

An ESP32-based robotic car controlled via Bluetooth using IBT-2 motor drivers. This project enables wireless control of a dual-motor robot with precise movement capabilities.

![RoboSoker Banner](https://via.placeholder.com/800x200/222/FFFFFF?text=RoboSoker+Bluetooth+Robot+Car)

## 🚀 Features

- **Bluetooth Control**: Wireless control via Bluetooth Serial
- **Dual Motor Control**: Independent control of left and right motors
- **Multiple Movement Modes**: 
  - Forward/Backward
  - Left/Right pivot turns
  - Diagonal movements (forward-left, forward-right, etc.)
  - Smooth stop function
- **IBT-2 Motor Drivers**: High-current capable motor drivers
- **ESP32 Powered**: Leverages ESP32's Bluetooth capabilities

## 🛠️ Hardware Components

- ESP32 Development Board
- IBT-2 Motor Drivers (x2)
- DC Motors with Wheels (x2)
- Li-ion Battery Pack (7.4V-12V)
- Chassis Frame
- Jumper Wires
- Breadboard (optional)

## 📋 Pin Configuration

| Component | ESP32 Pin | Description |
|-----------|-----------|-------------|
| Left Motor LPWM | GPIO 26 | Left motor forward PWM |
| Left Motor RPWM | GPIO 27 | Left motor reverse PWM |
| Right Motor LPWM | GPIO 25 | Right motor forward PWM |
| Right Motor RPWM | GPIO 33 | Right motor reverse PWM |

## 🔧 Installation & Setup

### 1. Hardware Connections
1. Connect left motor to IBT-2 driver 1
2. Connect right motor to IBT-2 driver 2
3. Wire IBT-2 PWM pins to ESP32 as per pin configuration
4. Connect battery to IBT-2 power inputs
5. Ensure proper grounding between all components

### 2. Software Setup
1. Install Arduino IDE with ESP32 support
2. Add BluetoothSerial library (usually included with ESP32 board package)
3. Upload the code to ESP32
4. Open Serial Monitor at 9600 baud rate

## 📱 Control Commands

| Command | Action | Description |
|---------|--------|-------------|
| `F` | Forward | Move straight forward |
| `B` | Backward | Move straight backward |
| `L` | Left | Pivot turn left |
| `R` | Right | Pivot turn right |
| `G` | Forward-Left | Diagonal forward left |
| `I` | Forward-Right | Diagonal forward right |
| `H` | Backward-Left | Diagonal backward left |
| `J` | Backward-Right | Diagonal backward right |
| `S` | Stop | Stop all motors |

## 🎮 Bluetooth Control App

You can use any Bluetooth serial terminal app:
- **Android**: Serial Bluetooth Terminal, Bluino Loader
- **iOS**: LightBlue, Bluetooth Terminal
- **Windows**: Tera Term, Putty (with Bluetooth)

**Device Name**: `ESP32_IBT2_RCcar`

## ⚙️ Configuration

### Motor Speed Adjustment
```cpp
int motorSpeed = 200;  // Change this value (0-255) to adjust speed
