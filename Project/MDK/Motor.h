#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "headfile.h"
//================================宏定义引脚=================================
#define Motor_left_gpio		P6_2
#define Motor_right_gpio	P6_1
#define MOTOR_LEFT_GPIO		P62
#define MOTOR_RIGHT_GPIO	P61
//================================自定义函数区间=============================
void Motor_init(void);
void Motor_Ctrl(void);
#endif