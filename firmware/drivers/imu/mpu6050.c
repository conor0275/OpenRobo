#include "mpu6050.h"
#include "i2c.h"
#include <math.h>

#define MPU6050_ADDR (0x68 << 1)

#define MPU6050_WHO_AM_I 0x75
#define MPU6050_PWR_MGMT_1 0x6B
#define MPU6050_ACCEL_XOUT_H 0x3B

static int16_t raw_data[7];

static int16_t read_word(uint8_t reg)
{
    uint8_t buf[2];

    HAL_I2C_Mem_Read(&hi2c1,
                     MPU6050_ADDR,
                     reg,
                     I2C_MEMADD_SIZE_8BIT,
                     buf,
                     2,
                     HAL_MAX_DELAY);

    return (int16_t)(buf[0] << 8 | buf[1]);
}

int mpu6050_init(void)
{
    uint8_t data;

    HAL_I2C_Mem_Read(&hi2c1,
                     MPU6050_ADDR,
                     MPU6050_WHO_AM_I,
                     I2C_MEMADD_SIZE_8BIT,
                     &data,
                     1,
                     HAL_MAX_DELAY);

    if (data != 0x68)
        return -1;

    data = 0;

    HAL_I2C_Mem_Write(&hi2c1,
                      MPU6050_ADDR,
                      MPU6050_PWR_MGMT_1,
                      I2C_MEMADD_SIZE_8BIT,
                      &data,
                      1,
                      HAL_MAX_DELAY);

    return 0;
}

int mpu6050_read_all(imu_data_t *imu)
{
    uint8_t buf[14];

    HAL_I2C_Mem_Read(&hi2c1,
                     MPU6050_ADDR,
                     MPU6050_ACCEL_XOUT_H,
                     I2C_MEMADD_SIZE_8BIT,
                     buf,
                     14,
                     HAL_MAX_DELAY);

    raw_data[0] = (int16_t)(buf[0] << 8 | buf[1]);
    raw_data[1] = (int16_t)(buf[2] << 8 | buf[3]);
    raw_data[2] = (int16_t)(buf[4] << 8 | buf[5]);
    raw_data[3] = (int16_t)(buf[8] << 8 | buf[9]);
    raw_data[4] = (int16_t)(buf[10] << 8 | buf[11]);
    raw_data[5] = (int16_t)(buf[12] << 8 | buf[13]);

    imu->ax = raw_data[0] / 16384.0f;
    imu->ay = raw_data[1] / 16384.0f;
    imu->az = raw_data[2] / 16384.0f;

    imu->gx = raw_data[3] / 131.0f;
    imu->gy = raw_data[4] / 131.0f;
    imu->gz = raw_data[5] / 131.0f;

    return 0;
}