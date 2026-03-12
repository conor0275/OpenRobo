#include "cli_task.h"
#include "cli.h"
#include "cmsis_os.h"

char rx_buffer[64];

void cli_task(void *argument)
{
    cli_init();

    while(1)
    {
        /*
        未来这里读取UART
        */

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}