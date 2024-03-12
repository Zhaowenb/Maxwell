#include "Screen.h"
void Screen_init(void)
{
	ips114_init();
	ips114_clear(BLUE);
}
//=====================================================================================
//选页面
void Screen_Choose_Page(void)
{
//==============================速度环=============================
	if(Screen_Page == 1)
	{
		ips114_clear(WHITE);
		ips114_showstr(30,0,"P");
		ips114_showstr(30,20,"I");
		ips114_showstr(30,70,"D");
		ips114_showfloat(60,0,PidI_L.Kp,2,3);
		ips114_showfloat(60,20,PidI_L.Ki,2,3);
		ips114_showfloat(60,70,PidI_L.Kd,2,3);//左
		ips114_showfloat(120,0,PidI_R.Kp,2,3);
		ips114_showfloat(120,20,PidI_R.Ki,2,3);
		ips114_showfloat(120,70,PidI_R.Kd,2,3);//右     
	}
//==============================角度环=============================
	if(Screen_Page == 2)
	{
		ips114_clear(YELLOW);
		ips114_showstr(30,0,"P");
		ips114_showstr(30,20,"I");
		ips114_showstr(30,70,"D");
		ips114_showfloat(60,0,PidP_Angle.Kp,2,3);
		ips114_showfloat(60,20,PidP_Angle.Ki,2,3);
		ips114_showfloat(60,70,PidP_Angle.Kd,2,3);
	}
}
//=================================================================
//选p i d 
void Screen_Choose_Pid(void)
{
	if(Pid_Choose == 1)
	{
		Screen_Choose_Page();
		ips114_showstr(0,0,"->");//p
	}
	if(Pid_Choose == 2)
	{
		Screen_Choose_Page();
		ips114_showstr(0,20,"->");//i
	}
	if(Pid_Choose == 3)
	{
		Screen_Choose_Page();
		ips114_showstr(0,70,"->");//d
	}
}
//=================================================================================
//自增0.1====================================================
void Screen_Pid_MAXIncrease(void)
{
	if(Screen_Page == 1) //速度环
	{
		if(Pid_Choose == 1)
		{
			PidI_L.Kp+=0.1;
			PidI_R.Kp+=0.1;
			ips114_showfloat(60,0,PidI_L.Kp,2,3);
			ips114_showfloat(120,0,PidI_R.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidI_L.Ki+=0.1;
			PidI_R.Ki+=0.1;
			ips114_showfloat(60,20,PidI_L.Ki,2,3);
			ips114_showfloat(120,20,PidI_R.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidI_L.Kd+=0.1;
			PidI_R.Kd+=0.1;
			ips114_showfloat(60,70,PidI_L.Kd,2,3);//左
			ips114_showfloat(120,70,PidI_R.Kd,2,3);//右    
		}	
	}
	if(Screen_Page == 2)//角度环
	{
		if(Pid_Choose == 1)
		{
			PidP_Angle.Kp+=0.1;
			ips114_showfloat(60,0,PidP_Angle.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidP_Angle.Ki+=0.1;
			ips114_showfloat(60,20,PidP_Angle.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidP_Angle.Kd+=0.1;
			ips114_showfloat(60,70,PidP_Angle.Kd,2,3);
		}
	}
}
//================================================================================
//自减0.1========================================================
void Screen_Pid_MAXDecrease(void)
{
	if(Screen_Page == 1) //速度环
	{
		if(Pid_Choose == 1)
		{
			PidI_L.Kp-=0.1;
			PidI_R.Kp-=0.1;
			ips114_showfloat(60,0,PidI_L.Kp,2,3);
			ips114_showfloat(120,0,PidI_R.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidI_L.Ki-=0.1;
			PidI_R.Ki-=0.1;
			ips114_showfloat(60,20,PidI_L.Ki,2,3);
			ips114_showfloat(120,20,PidI_R.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidI_L.Kd-=0.1;
			PidI_R.Kd-=0.1;
			ips114_showfloat(60,70,PidI_L.Kd,2,3);//左
			ips114_showfloat(120,70,PidI_R.Kd,2,3);//右    
		}	
	}
	if(Screen_Page == 2)//角度环
	{
		if(Pid_Choose == 1)
		{
			PidP_Angle.Kp-=0.1;
			ips114_showfloat(60,0,PidP_Angle.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidP_Angle.Ki-=0.1;
			ips114_showfloat(60,20,PidP_Angle.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidP_Angle.Kd-=0.1;
			ips114_showfloat(60,70,PidP_Angle.Kd,2,3);
		}
	}
}
//==============================================================================
//自增0.01===========================================================
void Screen_Pid_MINIncrease(void)
{
	if(Screen_Page == 1) //速度环
	{
		if(Pid_Choose == 1)
		{
			PidI_L.Kp+=0.01;
			PidI_R.Kp+=0.01;
			ips114_showfloat(60,0,PidI_L.Kp,2,3);
			ips114_showfloat(120,0,PidI_R.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidI_L.Ki+=0.01;
			PidI_R.Ki+=0.01;
			ips114_showfloat(60,20,PidI_L.Ki,2,3);
			ips114_showfloat(120,20,PidI_R.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidI_L.Kd+=0.01;
			PidI_R.Kd+=0.01;
			ips114_showfloat(60,70,PidI_L.Kd,2,3);//左
			ips114_showfloat(120,70,PidI_R.Kd,2,3);//右
		}	
	}
	if(Screen_Page == 2)//角度环
	{
		if(Pid_Choose == 1)
		{
			PidP_Angle.Kp+=0.01;
			ips114_showfloat(60,0,PidP_Angle.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidP_Angle.Ki+=0.01;
			ips114_showfloat(60,20,PidP_Angle.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidP_Angle.Kd+=0.01;
			ips114_showfloat(60,70,PidP_Angle.Kd,2,3);
		}
	}
}
//==============================================================================
//自减0.01==================================================
void Screen_Pid_MINDecrease(void)
{
	if(Screen_Page == 1) //速度环
	{
		if(Pid_Choose == 1)
		{
			PidI_L.Kp-=0.01;
			PidI_R.Kp-=0.01;
			ips114_showfloat(60,0,PidI_L.Kp,2,3);
			ips114_showfloat(120,0,PidI_R.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidI_L.Ki-=0.01;
			PidI_R.Ki-=0.01;
			ips114_showfloat(60,20,PidI_L.Ki,2,3);
			ips114_showfloat(120,20,PidI_R.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidI_L.Kd-=0.01;
			PidI_R.Kd-=0.01;
			ips114_showfloat(60,70,PidI_L.Kd,2,3);//左
			ips114_showfloat(120,70,PidI_R.Kd,2,3);//右    
		}	
	}
	if(Screen_Page == 2)//角度环
	{
		if(Pid_Choose == 1)
		{
			PidP_Angle.Kp-=0.01;
			ips114_showfloat(60,0,PidP_Angle.Kp,2,3);
		}
		if(Pid_Choose == 2)
		{
			PidP_Angle.Ki-=0.01;
			ips114_showfloat(60,20,PidP_Angle.Ki,2,3);
		}
		if(Pid_Choose == 3)
		{
			PidP_Angle.Kd-=0.01;
			ips114_showfloat(60,70,PidP_Angle.Kd,2,3);
		}
	}
}