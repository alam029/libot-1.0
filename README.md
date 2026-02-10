# 🏁 Smart Line Follower Robot with PID Control
This repository contains the source code and circuit design for an autonomous Line Follower Robot built using an Arduino Nano and a 5-channel IR sensor array. The robot uses a PID (Proportional-Integral-Derivative) controller to ensure smooth and precise line tracking.

**🚀 Features**
**PID Control:** Implements a feedback loop to minimize tracking errors and prevent overshooting.
**5-Channel IR Sensor:** High-resolution sensing to detect line positions with weighted error values.
**Efficient Power Management:** Powered by dual 18650 Li-ion batteries with a buck converter for stable voltage regulation.
**Robust Drive System:** Utilizes the TB6612FNG motor driver for high-efficiency dual DC motor control.

**🛠️ Components Used**
**Microcontroller:** Arduino Nano
**Motor Driver:** TB6612FNG
**Sensors:** 5-Way IR Reflectance Sensor Array
**Motors:** 2x N20 Gear Motors
**Power:** 2x 18650 Li-ion batteries, LM2596 Buck Converter, and a SPST Rocker Switch
**Software:** Arduino IDE, Cirkit Designer (for schematics)

**💻 Code Structure**
The core logic resides in the PID calculation within the loop() function:
**sensorValue():** Reads the IR sensors and returns a weighted error (from -2 to 2) based on the line's position.
**PID Calculation:** Computes the adjustment value using kp, ki, and kd constants.
**moveRobot(): **Adjusts the PWM duty cycle for each motor to steer the robot back onto the line.

**👥 Team Members**
1)
2)
3)
4)
5)

📜 License
This project is open-source and intended for educational, research, and competitive robotics use.
