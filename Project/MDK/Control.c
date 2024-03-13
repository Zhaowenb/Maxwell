#include "Control.h"
int out_dw = 0;
int out_R = 0;
int out_L = 0;
int dutyR = 0;
int dutyL = 0; 
int B11_sum=0;
int B11_errRL=0;
int B11_errLR=0;
int Dir_out=0;
int Dir_real;

int16   SpeedOut_L =  0;
int16   SpeedOut_R =  0;

void PidSpeed_Ctrl(void)
{
	Encoder_speed();
	SpeedOut_L = (float)PID_increase(&PidI_L,2000);
	SpeedOut_R = (float)PID_increase(&PidI_R,2000);
//	PidI_L.last_out = SpeedOut_L;
//	PidI_R.last_out = SpeedOut_R;
	Motor_Ctrl();
	//Beep_bee();
}
void Pid_Ctrl(void)
{
	
	Pid_Dir.real = LNow[BL1]-LNow[BR1];
	//Dir_real=LNow[BL1]-LNow[BR1];
	if(Pid_Dir.real<30) Pid_Dir.real=0;
	PID_position(&Pid_Dir,0);
	Dir_out=limit(Pid_Dir.out,1500);
	PID_increase(&PidI_L,-Dir_real);
	PID_increase(&PidI_R,Dir_real);
    PidI_L.last_out=limit(PidI_L.last_out,2000)+1000;
	PidI_R.last_out=limit(PidI_R.last_out,2000)+1000;	
	Motor_Ctrl();
////	Pid_Dir.real = LNow[BL1]-LNow[BR1];
//////	PID_position(&PidP_Angle,0);
//////	//PID_position(&Pid_Dir,0);
////	PID_position(&Pid_Dir,0);
//out_dw = dircontrol(LNow[BR1]-LNow[BL1]);
////	PID_increase(&PidI_L,1300+Pid_Dir.out); 
////	PID_increase(&PidI_R,1300-Pid_Dir.out);//串级pid
////	
////	out_L = PidI_L.last_out - Pid_Dir.out;
////	out_R = PidI_R.last_out - Pid_Dir.out;
//	PidI_L.last_out = (int16)PID_increase(&PidI_L,myabs(out_dw)); 
//	PidI_R.last_out = (int16)PID_increase(&PidI_R,myabs(out_dw));
//	PidI_L.last_out=limit(PidI_L.last_out,2000);
//	PidI_R.last_out=limit(PidI_R.last_out,2000);       //240306
////	
////	PidI_L.last_out=limit(PidI_L.last_out,2000);
////	PidI_R.last_out=limit(PidI_R.last_out,2000);

////	Motor_set_PWM();
////	if(Pid_Dir.out)
////	{
////		Beep_bee();
////	}
////	else ;
////PID_increase(&PidI_L,LNow[BR1]/10); 
////PID_increase(&PidI_R,LNow[BL1]/10); 
////B11_sum=LNow[BR1]+LNow[BL1];
////B11_errRL=LNow[BR1]-LNow[BL1];
////B11_errLR=LNow[BL1]-LNow[BR1];
////PidI_L.last_out=(uint32)(B11_errRL*100.0f/B11_sum);
////PidI_R.last_out=(uint32)(B11_errLR*100.0f/B11_sum);
////PID_increase(&PidI_L,myabs(Pid_Dir.out)); 
////PID_increase(&PidI_R,myabs(Pid_Dir.out));//串级pid
////PidI_L.last_out=limit(PidI_L.last_out,2000);
////PidI_R.last_out=limit(PidI_R.last_out,2000);
//Motor_Ctrl();
////Pid_Ctrl2();

}
void Pid_Ctrl2(void)
{
	My_center_mag(0);
	out_dw = dircontrol(deviation);
	//out_dw = limit(out_dw,30000);
	PID_increase(&PidI_L,+myabs(out_dw));
	PID_increase(&PidI_R,myabs(out_dw));
	PidI_L.last_out=limit(PidI_L.last_out,2000)+800;
	PidI_R.last_out=limit(PidI_R.last_out,2000)+800;
//	PidI_L.last_out=PidI_L.last_out+800;
//	PidI_R.last_out=PidI_R.last_out+800;		
	Motor_Ctrl();
	out_L = (int16)PID_increase(&PidI_L,out_dw);       
	out_R = (int16)PID_increase(&PidI_R,out_dw);
	dutyL = out_L - out_dw;
	dutyR = out_R + out_dw;	
	Motor_set_PWM();
}
////=================================================================
////方向环，驱动电机实现差速转弯
////=================================================================
float dir_p =150;
float dir_i = 0;
float dir_d = 20;
int output;
int total_i;
int last_chazhi;
int dircontrol(int chazhi)
{
	total_i+=chazhi;
	output = (int)(chazhi*dir_p+dir_i*total_i+(chazhi-last_chazhi)*dir_d);
	last_chazhi = chazhi;
	return output;
}
void Motor_set_PWM(void)
{
	PidI_R.last_out = dutyR;
	PidI_L.last_out = dutyL;
}
