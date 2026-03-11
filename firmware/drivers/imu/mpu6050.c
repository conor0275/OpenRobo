#include "mpu6050.h"
#include <math.h>

/*
 * Fake IMU generator
 * Used before hardware is available
 */

static float time_sim = 0.0f;


void mpu6050_init(void)
{
    /* nothing to do for fake driver */
}


/*
 * Generate simulated IMU data
 */
void mpu6050_read_all(imu_data_t *imu)
{
    time_sim += 0.01f;

    imu->ax = 0.0f;
    imu->ay = 0.0f;
    imu->az = 1.0f;

    imu->gx = sinf(time_sim) * 20.0f;
    imu->gy = cosf(time_sim) * 15.0f;
    imu->gz = 0.0f;
}