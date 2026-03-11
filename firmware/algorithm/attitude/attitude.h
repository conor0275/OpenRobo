#ifndef ATTITUDE_H
#define ATTITUDE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "mpu6050.h"

/*
 * Initialize attitude estimator
 */
void attitude_init(void);


/*
 * Update attitude
 */
void attitude_update(const imu_data_t *imu, float dt);


/*
 * Get roll angle
 */
float attitude_get_roll(void);


/*
 * Get pitch angle
 */
float attitude_get_pitch(void);


/*
 * Get yaw angle
 */
float attitude_get_yaw(void);


#ifdef __cplusplus
}
#endif

#endif