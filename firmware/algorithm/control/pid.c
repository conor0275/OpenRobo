#include "pid.h"

void pid_init(pid_t *pid,float kp,float ki,float kd)
{
    pid->kp=kp;
    pid->ki=ki;
    pid->kd=kd;

    pid->integral=0;
    pid->last_error=0;
}

float pid_update(pid_t *pid,float target,float measurement)
{
    float error = target-measurement;

    pid->integral += error;

    float derivative = error - pid->last_error;

    pid->last_error = error;

    return pid->kp*error
           +pid->ki*pid->integral
           +pid->kd*derivative;
}