#include "encoder.h"
#include "tim.h"


/*读取编码器的反馈值*/
int read_encoder(int TIMX)
{
	 int Encoder_TIM;    
	 switch(TIMX)
	 {
		case 2:  Encoder_TIM= (short)TIM2 -> CNT;   TIM2 -> CNT=0;  break;
		case 3:  Encoder_TIM= (short)TIM3 -> CNT;   TIM3 -> CNT=0;  break;
		case 4:  Encoder_TIM= (short)TIM4 -> CNT;   TIM4 -> CNT=0;  break;	
		case 5:  Encoder_TIM= (short)TIM5 -> CNT;   TIM5 -> CNT=0;  break;	
		default: Encoder_TIM=0;
	 }
		return Encoder_TIM;
}

/*计算电机速度，在定时器 TIM3 里面每 1ms 调用一次*/
int motor_calc(int ppr, int frequency, int ratio, float time_coefficient)
{
	int encoderNum = 0;  //编码器计数
    float rotateSpeed = 0;  //转速
	int total_resolution = ppr * frequency * ratio; //总分辨率
    
    /*读取编码器的值，正负代表旋转方向*/
    encoderNum = read_encoder(4);
    /* 转速(1秒钟转多少圈)=单位时间内的计数值/总分辨率*时间系数 */
    rotateSpeed = (float)encoderNum/total_resolution*time_coefficient*60;
		
	return rotateSpeed;
}