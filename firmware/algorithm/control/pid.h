#ifndef PID_H
#define PID_H

typedef struct
{
    float kp;
    float ki;
    float kd;

    float integral;
    float last_error;

} pid_t;

void pid_init(pid_t *pid,float kp,float ki,float kd);

float pid_update(pid_t *pid,float target,float measurement);

#endif