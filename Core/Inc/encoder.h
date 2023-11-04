#ifndef _ENCODER_H_
#define _ENCODER_H_

struct Motor
{
	int rpm;
	int direction;
};

int Read_Encoder(int TIMX);

int motor_calc(int ppr, int frequency, int ratio, float time_coefficient);

#endif