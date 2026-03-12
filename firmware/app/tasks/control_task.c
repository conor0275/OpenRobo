#include "control_task.h"
#include "cmsis_os.h"

void control_task(void *argument)
{
    while(1)
    {
        /*
        未来运行 PID
        */

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}