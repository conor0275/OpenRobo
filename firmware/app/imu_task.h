#ifndef IMU_TASK_H
#define IMU_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * FreeRTOS task for IMU processing
 */
void imu_task(void *argument);

#ifdef __cplusplus
}
#endif

#endif