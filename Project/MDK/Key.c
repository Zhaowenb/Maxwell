#include "Key.h"
uint32 KEYS1_Flag = 0;
uint32 KEYS2_Flag = 0;
uint32 KEYLeft_Flag = 0;
uint32 KEYRight_Flag = 0;
uint32 KEYUp_Flag = 0;
uint32 KEYDown_Flag = 0;
uint32 KEYCENTER_Flag = 0;
uint32 Screen_Page = 0;        //��Ļҳ��
uint32 Pid_Choose=0;           //pidѡ����� 1Ϊp 2Ϊi 3Ϊd                 M
//===================================������ʼ��===========================  V
void Key_init(void)
{
	gpio_mode(KeyS1,2);
	gpio_pull_set(KeyS1,PULLUP);//KEYS1��ʼ��
	gpio_mode(KeyS2,2);
	gpio_pull_set(KeyS2,PULLUP);//KEYS2��ʼ��
	gpio_mode(KeyLeft,2);
	gpio_pull_set(KeyLeft,PULLUP);//KEYA��ʼ��
	gpio_mode(KeyRight,2);
	gpio_pull_set(KeyRight,PULLUP);//KEYB��ʼ��
	gpio_mode(KeyUp,2);
	gpio_pull_set(KeyUp,PULLUP);//KEYC��ʼ��
	gpio_mode(KeyDown,2);
	gpio_pull_set(KeyDown,PULLUP);//KEYD��ʼ��
	gpio_mode(KeyCenter,2);
	gpio_pull_set(KeyCenter,PULLUP);//KEYCENTER��ʼ��
}
//================================����ɨ��========================================
void Key_Scan(void)
{
	if(KEYS1 == 0)         //ɨ�谴��KEYS1  �²��ұߵİ���
	{
		delay_ms(10);
		if(KEYS1 == 0)
		{
			KEYS1_Flag = 1;
		}
		while(KEYS1 == 0);
	}
	
	if(KEYS2 == 0)			//ɨ�谴��KEYS2	 �²���ߵİ���
	{
		delay_ms(10);
		if(KEYS2 == 0)
		{
			KEYS2_Flag = 1;
		}
		while(KEYS2 == 0);
	}
	
	if(KEYRight == 0)			//ɨ�谴��KEYRight
	{
		delay_ms(10);
		if(KEYRight == 0)
		{
			KEYRight_Flag = 1;
		}
		while(KEYRight == 0);
	}
	
	if(KEYLeft == 0)			//ɨ�谴��KEYLeft
	{
		delay_ms(10);
		if(KEYLeft == 0)
		{
			KEYLeft_Flag = 1;
		}
		while(KEYLeft == 0);
	}
	
	if(KEYUp == 0)			//ɨ�谴��KEYUp
	{
		delay_ms(10);
		if(KEYUp == 0)
		{
			KEYUp_Flag = 1;
		}
		while(KEYUp == 0);
	}
	
	if(KEYDown == 0)			//ɨ�谴��KEYDown
	{
		delay_ms(10);
		if(KEYDown == 0)
		{
			KEYDown_Flag = 1;
		}
		while(KEYDown == 0);
	}
	
	if(KEYCENTER == 0)		//ɨ�谴��KEYCENTER
	{
		delay_ms(10);
		if(KEYCENTER == 0)
		{
			KEYCENTER_Flag = 1;
		}
		while(KEYCENTER == 0);
	}
}
//=============================================================
//�˻���������================================
void Key_Screen(void)
{
	if(KEYS1_Flag == 1)
	{
		if(Screen_Page < 2) 
			Screen_Page++;
		else  				
			Screen_Page = 1;
		Screen_Choose_Page();
		KEYS1_Flag = 0;
	}
	if(Screen_Page==1||Screen_Page==2)
	{
		if(KEYCENTER_Flag == 1)
		{
			if(Pid_Choose < 3)
				Pid_Choose++;
			else Pid_Choose = 1;
			Screen_Choose_Pid();
			KEYCENTER_Flag = 0;
		}
	}
	if(KEYUp_Flag == 1)
	{
		Screen_Pid_MAXIncrease();
		KEYUp_Flag = 0;
	}
	if(KEYDown_Flag == 1)
	{
		Screen_Pid_MAXDecrease();
		KEYDown_Flag = 0;
	}
	if(KEYLeft_Flag == 1)
	{
		Screen_Pid_MINDecrease();
		KEYLeft_Flag = 0;
	}
	if(KEYRight_Flag == 1)
	{
		Screen_Pid_MINIncrease();
		KEYRight_Flag = 0;
	}
}