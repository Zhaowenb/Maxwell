#ifndef __SCREEN_H_
#define __SCREEN_H_
#include "headfile.h"
//==================================ȫ�ֱ���=====================================
extern uint32 Screen_Page;        //��Ļҳ��
extern uint32 Pid_Choose;           //pidѡ����� 1Ϊp 2Ϊi 3Ϊd
//======================================�Զ��庯������===========================
void Screen_init(void);
void Screen_Choose_Page(void);
void Screen_Choose_Pid(void);
void Screen_Pid_MAXIncrease(void);//+0.1
void Screen_Pid_MAXDecrease(void);//-0.1
void Screen_Pid_MINIncrease(void);//+0.01
void Screen_Pid_MINDecrease(void);//-0.01
//===============================================================================
#endif
