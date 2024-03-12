#ifndef __CONTROL_H_
#define __CONTROL_H_
#include "headfile.h"

void Pid_Ctrl(void);
extern int dircontrol(int chazhi);
void Motor_set_PWM(void);
void Pid_Ctrl2(void);
extern void My_center_mag(uint8 i);

#endif
