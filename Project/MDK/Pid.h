#ifndef		__PID_H_
#define		__PID_H_

#include "headfile.h"

typedef	struct
{
	float Kp;
	float Ki;
	float Kd;
	float bias;
	float	before_bias;	
	float integral;
	float derivative;
	float target;
	float	real;
	float out;
}PID_POS;

typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float bias;
	float before_bias;
	float before_before_bias;
	float integral;
	float derivative;
	float	target;
	float	real;
	float out;
	float last_out;
}PID_INC;


extern  PID_POS  PidP_Angle;
extern  PID_INC  PidI_L;
extern	PID_INC	 PidI_R;
extern  PID_POS  Pid_Dir;



void	PID_ALL_Init(void);
void 	PID_Pos_Init(PID_POS * PID,float p,float i,float d);
void 	PID_Inc_Init(PID_INC * PID,float p,float i,float d);
int16	PID_position(PID_POS * PID,float t);
int16 	PID_increase(PID_INC * PID,float t);

#endif