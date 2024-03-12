#include "Pid.h"

PID_POS  PidP_Angle;
PID_POS  Pid_Dir;
PID_INC  PidI_L;
PID_INC	 PidI_R;

void	PID_ALL_Init(void)
{
	//PID_Pos_Init(&PidP_Angle,0,0,0);
	//PID_Pos_Init(&Pid_Dir,0.6,0,0.75);
//	PID_Inc_Init(&Pid_Dir,5,1,5);
	PID_Inc_Init(&PidI_L,0.8,0.1,0.1);
	PID_Inc_Init(&PidI_R,0.8,0.1,0.1);
}

void 	PID_Pos_Init(PID_POS *PID,float p,float i,float d)
{
		PID->Kp = p;
		PID->Ki = i;
		PID->Kd = d;
		PID->target = 0.0;
		PID->integral = 0.0;
		PID->derivative = 0.0;
		PID->bias = 0.0;
		PID->before_bias = 0.0;
		PID->real = 0.0;
		PID->out = 0.0;
}

void 	PID_Inc_Init(PID_INC *PID,float p,float i,float d)
{
		PID->Kp = p;
		PID->Ki = i;
		PID->Kd = d;
		PID->target = 0.0;
		PID->bias = 0.0;
		PID->before_bias = 0.0;
		PID->before_before_bias = 0.0;
		PID->integral = 0.0;
		PID->derivative = 0.0;
		PID->real = 0.0;
		PID->out = 0.0;
		PID->last_out = 0.0;
}

int16	PID_position(PID_POS *PID,float t)
{
		PID->target = t;
		PID->bias = PID->target - PID->real;
		PID->integral += PID->bias;
		PID->out = PID->Kp * PID->bias + PID->Ki * PID->integral + PID->Kd *(PID->bias - PID->before_bias);
		PID->before_bias = PID->bias;
		return PID->out; 
}

int16 	PID_increase(PID_INC * PID,float t)
{
		PID->target = t;
		PID->bias = PID->target - PID->real;
		PID->out = PID->Kp * (PID->bias - PID->before_bias) + PID->Ki * PID->bias + PID->Kd * (PID->bias - 2*PID->before_bias + PID->before_before_bias);
		PID->before_before_bias = PID->before_bias; 
		PID->before_bias = PID->bias;
		PID->last_out += PID->out;
		return PID->last_out;
}
