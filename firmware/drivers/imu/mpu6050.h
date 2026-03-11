#ifndef MPU6050_H
#define MPU6050_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
 * IMU data structure
 * All values are in physical units
 */
typedef struct
{
    float ax;
    float ay;
    float az;

    float gx;
    float gy;
    float gz;

} imu_data_t;


/*
 * Initialize MPU6050
 */
void mpu6050_init(void);


/*
 * Read all IMU data
 */
void mpu6050_read_all(imu_data_t *imu);


#ifdef __cplusplus
}
#endif

#endif