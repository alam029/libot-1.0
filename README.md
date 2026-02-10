# 🏁 Smart Line Follower Robot with PID Control

This repository contains the source code and circuit design for an
autonomous **Line Follower Robot** built using an **Arduino Nano** and a
**5-channel IR sensor array**. The robot employs a **PID
(Proportional--Integral--Derivative) control algorithm** to achieve
smooth, stable, and precise line tracking.

------------------------------------------------------------------------

## 🚀 Features

-   **PID Control:** Implements a closed-loop feedback system to
    minimize tracking errors, reduce oscillations, and prevent
    overshooting.
-   **5-Channel IR Sensor Array:** Provides high-resolution line
    detection with weighted error calculation for accurate positioning.
-   **Efficient Power Management:** Powered by dual 18650 Li-ion
    batteries with a buck converter to ensure stable voltage regulation.
-   **Robust Drive System:** Uses the TB6612FNG motor driver for
    efficient and reliable dual DC motor control.

------------------------------------------------------------------------

## 🛠️ Components Used

-   **Microcontroller:** Arduino Nano
-   **Motor Driver:** TB6612FNG
-   **Sensors:** 5-Way IR Reflectance Sensor Array
-   **Motors:** 2× N20 DC Gear Motors
-   **Power Supply:**
    -   2× 18650 Li-ion Batteries
    -   LM2596 Buck Converter
    -   SPST Rocker Switch
-   **Software Tools:**
    -   Arduino IDE
    -   Cirkit Designer (for circuit schematics)

------------------------------------------------------------------------

## 💻 Code Structure

The core control logic is implemented inside the `loop()` function using
a PID controller.

-   **sensorValue():**\
    Reads data from the IR sensors and returns a weighted error value
    ranging from **-2 to +2**, depending on the position of the line.

-   **PID Calculation:**\
    Computes the correction value using the tuned PID constants (`kp`,
    `ki`, `kd`) based on current, accumulated, and previous errors.

-   **moveRobot():**\
    Adjusts the PWM duty cycle of each motor to steer the robot back
    toward the center of the line.

------------------------------------------------------------------------

## 📜 License

This project is open-source and intended for **educational, research,
and competitive robotics** use.
