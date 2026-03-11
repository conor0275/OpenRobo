#include "imu_task.h"
#include "imu_interface.h"
#include "attitude.h"
#include "log.h"

#include "cmsis_os.h"

void imu_task(void *argument)
{
    imu_data_t imu;

    const float dt = 0.005f;

    imu_init();

    while (1)
    {
        imu_read(&imu);

        attitude_update(&imu, dt);

        float roll = attitude_get_roll();
        float pitch = attitude_get_pitch();
        float yaw = attitude_get_yaw();

        log_info("roll %.2f pitch %.2f yaw %.2f\r\n",
                 roll, pitch, yaw);

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}