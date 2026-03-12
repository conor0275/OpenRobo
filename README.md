# OpenRobo

OpenRobo is an open-source modular robot controller based on STM32.

## Features

- FreeRTOS based architecture
- Modular driver framework
- IMU attitude estimation
- UART logging
- Designed for real robots

## Hardware

MCU
STM32F103C8T6

IMU
MPU6050

## System Architecture

Application Layer
Robot tasks

Algorithm Layer
Attitude estimation

Driver Layer
Sensor drivers

Hardware Layer
STM32 peripherals

## Roadmap

v0.1
IMU attitude estimation

v0.2
Sensor framework

v0.3
Motor control

v0.4
Self balancing robot

v0.5
Communication system

+-------------+
| Application |
+-------------+

+-------------+
| Algorithm   |
+-------------+

+-------------+
| Middleware  |
+-------------+

+-------------+
| Driver      |
+-------------+

+-------------+
| Hardware    |
+-------------+