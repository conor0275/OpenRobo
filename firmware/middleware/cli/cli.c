#include "cli.h"
#include "string.h"
#include "log.h"
#include "attitude.h"

void cli_init(void)
{
    LOG_INFO("CLI ready\r\n");
}

void cli_process(char *cmd)
{
    if(strcmp(cmd,"help")==0)
    {
        LOG_INFO("commands:\r\n");
        LOG_INFO("imu\r\n");
        LOG_INFO("status\r\n");
    }

    else if(strcmp(cmd,"imu")==0)
    {
        float roll = attitude_get_roll();
        float pitch = attitude_get_pitch();
        float yaw = attitude_get_yaw();

        LOG_INFO("roll %.2f pitch %.2f yaw %.2f\r\n",
        roll,pitch,yaw);
    }

    else if(strcmp(cmd,"status")==0)
    {
        LOG_INFO("system ok\r\n");
    }

    else
    {
        LOG_INFO("unknown command\r\n");
    }
}