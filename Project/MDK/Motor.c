#include "Motor.h"
void Motor_init(void)
{
    pwm_init(PWMA_CH1P_P60, 17000,0);		//右轮控速
	gpio_mode(Motor_right_gpio,GPO_PP);
	MOTOR_RIGHT_GPIO = 1;					//赋值为1为正转

	pwm_init(PWMA_CH2N_P63, 17000,0);     	//左轮控速  
	gpio_mode(Motor_left_gpio,GPO_PP);
	MOTOR_LEFT_GPIO = 0;				//赋值为1为正转(为0 or 1需自测)
}	
void Motor_Ctrl(void)               		//控制电机正反转
{
	if(LNor[BL1]+LNor[BR1]>30)
	{
	   if(PidI_R.last_out>=0)
	   {
		   MOTOR_RIGHT_GPIO = 1;//右轮正转
		   pwm_duty(PWMA_CH1P_P60,PidI_R.last_out);
	   }
	   else
	   {
		   MOTOR_RIGHT_GPIO = 0;//右轮反转
		   pwm_duty(PWMA_CH1P_P60,(-1)*PidI_R.last_out);
	   }
	   if(PidI_L.last_out>=0)
	   {
		   MOTOR_LEFT_GPIO = 1;
		   pwm_duty(PWMA_CH2N_P63, PidI_L.last_out);
	   }
	   else
	   {
		   MOTOR_LEFT_GPIO = 0;
		   pwm_duty(PWMA_CH2N_P63,(-1)*PidI_L.last_out);
	   }
	}
	else
	{
	pwm_duty(PWMA_CH1P_P60,0);
	pwm_duty(PWMA_CH2N_P63,0);
	}
}