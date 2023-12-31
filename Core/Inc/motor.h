#ifndef _MOTOR_H_
#define _MOTOR_H_

typedef struct _pid_struct_t
{
  float kp;
  float ki;
  float kd;
  float i_max;
  float out_max;
  
  float ref;      // target value
  float fdb;      // feedback value  
  float err[2];   // error and last error

  float p_out;
  float i_out;
  float d_out;
  float output;
}pid_struct_t;

void pid_init(pid_struct_t *pid, float kp, float ki,float kd, float i_max, float out_max);

float pid_calc(pid_struct_t *pid, float ref, float fdb);

int r_to_pwm(int r);

#endif