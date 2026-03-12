#include "cmsis_os.h"
#include "log.h"

void log_task(void *argument)
{
    while(1)
    {
        LOG_INFO("system running\r\n");

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}