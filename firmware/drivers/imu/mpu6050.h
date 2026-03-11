#ifndef MPU6050_H
#define MPU6050_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct
{
    float ax;
    float ay;
    float az;

    float gx;
    float gy;
    float gz;

} imu_data_t;

int mpu6050_init(void);

int mpu6050_read_all(imu_data_t *imu);

#ifdef __cplusplus
}
#endif

#endif