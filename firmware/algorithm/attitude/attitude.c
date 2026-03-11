#include "attitude.h"
#include <math.h>

/*
 * Internal attitude state
 */

static float roll = 0.0f;
static float pitch = 0.0f;
static float yaw = 0.0f;

#define RAD_TO_DEG 57.29578f

/*
 * Complementary filter coefficient
 */
#define ALPHA 0.98f


void attitude_init(void)
{
    roll = 0.0f;
    pitch = 0.0f;
    yaw = 0.0f;
}


/*
 * Update attitude estimation
 */
void attitude_update(const imu_data_t *imu, float dt)
{
    float accel_roll;
    float accel_pitch;

    /* calculate roll/pitch from accelerometer */
    accel_roll = atan2f(imu->ay, imu->az) * RAD_TO_DEG;
    accel_pitch = atan2f(-imu->ax, imu->az) * RAD_TO_DEG;

    /* gyro integration */
    roll += imu->gx * dt;
    pitch += imu->gy * dt;
    yaw += imu->gz * dt;

    /* complementary filter */
    roll = ALPHA * roll + (1.0f - ALPHA) * accel_roll;
    pitch = ALPHA * pitch + (1.0f - ALPHA) * accel_pitch;
}


float attitude_get_roll(void)
{
    return roll;
}


float attitude_get_pitch(void)
{
    return pitch;
}


float attitude_get_yaw(void)
{
    return yaw;
}