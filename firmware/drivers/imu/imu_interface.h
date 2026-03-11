#ifndef IMU_INTERFACE_H
#define IMU_INTERFACE_H

#include "mpu6050.h"

int imu_init(void);

int imu_read(imu_data_t *imu);

#endif