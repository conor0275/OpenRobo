#include "imu_interface.h"
#include "mpu6050.h"

int imu_init(void)
{
    return mpu6050_init();
}

int imu_read(imu_data_t *imu)
{
    return mpu6050_read_all(imu);
}