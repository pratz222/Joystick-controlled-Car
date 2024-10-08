# Joystick-Controlled Car

## Overview

The Joystick-Controlled Car project allows users to control a car using a joystick interface through Bluetooth communication. This project utilizes the RemoteXY library for creating a mobile application to send commands from a smartphone to an ESP32 microcontroller. The car responds to joystick movements and button presses, enabling forward, backward, left, and right movement, as well as opening and closing actions.

## Functionality

- **Joystick Control**: The car can move in all directions based on the joystick's position.
  - **Forward**: Joystick pushed forward.
  - **Backward**: Joystick pulled backward.
  - **Left**: Joystick moved left.
  - **Right**: Joystick moved right.
  
- **Button Control**: Additional controls for opening and closing mechanisms (e.g., a grabber or a container).
  - **Button 1**: Open action.
  - **Button 2**: Move up.
  - **Button 3**: Move down.
  - **Button 4**: Close action.

## Hardware Setup

### Components Required:
- **Microcontroller**: ESP32
- **DC Motors**: 4 motors for movement
- **Motor Driver**: (e.g., L298N or similar) to control the motors
- **Joystick Module**: for control input
- **Power Supply**: Suitable battery or power bank for the motors and ESP32

### Wiring:
1. Connect the DC motors to the motor driver as follows:
   - Motor 1: `motor1_1` to pin 23, `motor1_2` to pin 22
   - Motor 2: `motor2_1` to pin 1, `motor2_2` to pin 3
   - Motor 3: `motor3_1` to pin 21, `motor3_2` to pin 19
   - Motor 4: `motor4_1` to pin 18, `motor4_2` to pin 5
2. Connect the joystick module to the ESP32. The analog output pins of the joystick will be connected to the appropriate analog input pins on the ESP32.
3. Ensure the motor driver is powered correctly with an external power source.

## Code Explanation

### Library Inclusions and Configuration
- The project includes the necessary libraries for Bluetooth communication and RemoteXY configuration.

```cpp
#include <BLEDevice.h>
#include <RemoteXY.h>
```

### RemoteXY Configuration
- The configuration for the RemoteXY interface is set, including the Bluetooth name and control layout.

### Structure Definition
- A structure defines all the input variables and connection status for the RemoteXY interface.


### Setup Function
- Initializes RemoteXY and sets up the motor control pins.

### Loop Function
- The loop continuously handles input from the joystick and buttons, controlling the motors accordingly.

### Motor Control Logic
- Each control condition checks the state of buttons or joystick position to determine which motors to activate for movement or actions.

## Conclusion

The Joystick-Controlled Car project provides a hands-on experience with wireless control of a robotic vehicle using Bluetooth technology. It can be further enhanced with additional features such as obstacle detection and path following, making it a versatile project for learning about robotics and IoT.
