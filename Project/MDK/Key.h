#ifndef __KEY_H_
#define __KEY_H_

#include "headfile.h"
//======================宏定义区间=================================
#define KeyS1		P7_1
#define KeyS2		P0_1
#define KeyRight	P3_7
#define KeyLeft		P3_6
#define KeyUp		P7_0
#define KeyDown		P4_1
#define KeyCenter	P7_2

#define KEYS1		P71
#define KEYS2		P01
#define KEYRight	P37//右
#define KEYLeft		P36//左
#define KEYUp		P70//上
#define KEYDown		P41//下
#define KEYCENTER   P72
//===================================================================
//======================自定义函数区间===============================
void Key_init(void);
void Key_Scan(void);
void Key_Screen(void);
//=====================================================================


#endif
