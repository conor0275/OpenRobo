#include "board.h"
#include "mpu6050.h"
#include "attitude.h"
#include "imu_task.h"

int main(void)
{
    board_init();

    mpu6050_init();

    attitude_init();

    /* create FreeRTOS task */

    osKernelStart();

    while (1)
    {
    }
}