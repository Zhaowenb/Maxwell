#ifndef __KEY_H_
#define __KEY_H_

#include "headfile.h"
//======================�궨������=================================
#define KeyS1		P7_1
#define KeyS2		P0_1
#define KeyRight	P3_7
#define KeyLeft		P3_6
#define KeyUp		P7_0
#define KeyDown		P4_1
#define KeyCenter	P7_2

#define KEYS1		P71
#define KEYS2		P01
#define KEYRight	P37//��
#define KEYLeft		P36//��
#define KEYUp		P70//��
#define KEYDown		P41//��
#define KEYCENTER   P72
//===================================================================
//======================�Զ��庯������===============================
void Key_init(void);
void Key_Scan(void);
void Key_Screen(void);
//=====================================================================


#endif
