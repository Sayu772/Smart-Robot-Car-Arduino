# Smart-Robot-Car-Arduino
An Arduino-based smart robot car featuring two functional modes: Autonomous Obstacle Avoiding and Bluetooth Remote Control, programmed in C/C++.
# 🤖 Smart Robot Car (Dual Mode)

An advanced Arduino-based Smart Robot Car capable of operating in two functional modes: **Autonomous Obstacle Avoiding** and **Manual Bluetooth/Serial Remote Control**. This project demonstrates embedded systems development, hardware-software integration, and real-time sensor data processing using C/C++.

---

## 🚀 Features

*   **Dual Operation Modes:** Easily switch between Manual and Autonomous modes via serial commands.
*   **Autonomous Obstacle Avoidance:** Uses an Ultrasonic Sensor mounted on a Servo Motor to scan 180 degrees, calculate distances, and intelligently navigate away from obstacles.
*   **Manual Remote Control:** Provides responsive directional movement (Forward, Backward, Left, Right, Stop) via Bluetooth/Serial commands.
*   **Dynamic Speed Control:** Configured with PWM pins (`ENA`, `ENB`) for optimized motor speed stabilization.

---

## 🛠️ Hardware & Components Used

*   **Microcontroller:** Arduino Uno (or compatible AVR board)
*   **Sensor:** HC-SR04 Ultrasonic Sensor (Distance detection)
*   **Actuator:** SG90 Servo Motor (Sensor rotation)
*   **Motor Driver:** L298N Dual H-Bridge Motor Driver
*   **Chassis:** 4WD / 2WD Robot Car Chassis with DC Gear Motors
*   **Communication:** HC-05/HC-06 Bluetooth Module (For wireless serial control)

---

## 📌 Pin Mapping

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **Ultrasonic Trigger** | Pin 8 | Sends sonar pulses |
| **Ultrasonic Echo** | Pin 9 | Receives sonar pulses |
| **Servo Motor** | Pin 10 | Rotates the Ultrasonic sensor |
| **Motor ENA / ENB** | Pin 11 / Pin 5 | Speed Control (PWM) |
| **Motor IN1 / IN2** | Pin 12 / Pin 13 | Left Motors Direction |
| **Motor IN3 / IN4** | Pin 7 / Pin 6 | Right Motors Direction |

---

## 📱 Serial Controls (API / Command Map)

When in **Manual Mode**, the robot responds to the following character streams over Serial/Bluetooth:

*   `6` - Switch to **Manual Mode**
*   `5` - Switch to **Autonomous Obstacle Avoiding Mode**
*   `1` - Move Forward
*   `2` - Move Backward
*   `3` - Turn Left
*   `4` - Turn Right
*   `0` - Stop

---

## 💻 Tech Stack & Concepts Demonstrated

*   **Language:** C / C++ (Arduino Sketch)
*   **Libraries:** `Ultrasonic.h`, `Servo.h`
*   **Concepts:** Embedded C Programming, Pulse Width Modulation (PWM), H-Bridge Motor Control, Ultrasonic Distance Calculation, Finite State Control logic.

---

## ⚙️ Installation & Setup

1. Clone this repository:
   ```bash
   git clone https://github.com
   ```
2. Open `sketch_oct26a.ino` in the Arduino IDE.
3. Install the required `Ultrasonic` library via the Library Manager.
4. Connect the hardware according to the **Pin Mapping** section.
5. Upload the code to your Arduino board and enjoy!
6.
