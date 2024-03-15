#include "Motor.h"
void Motor_init(void)
{
    pwm_init(PWMA_CH1P_P60, 17000,0);		//���ֿ���
	gpio_mode(Motor_right_gpio,GPO_PP);
	MOTOR_RIGHT_GPIO = 1;					//��ֵΪ1Ϊ��ת

	pwm_init(PWMA_CH2N_P63, 17000,0);     	//���ֿ���  
	gpio_mode(Motor_left_gpio,GPO_PP);
	MOTOR_LEFT_GPIO = 0;				//��ֵΪ1Ϊ��ת(Ϊ0 or 1���Բ�)
}	
void Motor_Ctrl(void)               		//���Ƶ������ת
{
	if(LNor[BL1]+LNor[BR1]>30)
	{
	   if(PidI_R.last_out>=0)
	   {
		   MOTOR_RIGHT_GPIO = 1;//������ת
		   pwm_duty(PWMA_CH1P_P60,PidI_R.last_out);
	   }
	   else
	   {
		   MOTOR_RIGHT_GPIO = 0;//���ַ�ת
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