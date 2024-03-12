#ifndef __SCREEN_H_
#define __SCREEN_H_
#include "headfile.h"
//==================================全局变量=====================================
extern uint32 Screen_Page;        //屏幕页数
extern uint32 Pid_Choose;           //pid选择变量 1为p 2为i 3为d
//======================================自定义函数区间===========================
void Screen_init(void);
void Screen_Choose_Page(void);
void Screen_Choose_Pid(void);
void Screen_Pid_MAXIncrease(void);//+0.1
void Screen_Pid_MAXDecrease(void);//-0.1
void Screen_Pid_MINIncrease(void);//+0.01
void Screen_Pid_MINDecrease(void);//-0.01
//===============================================================================
#endif
