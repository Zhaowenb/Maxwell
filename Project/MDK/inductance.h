#ifndef _INDUCTANCE_H_
#define _INDUCTANCE_H_
#include "headfile.h"
#define BL1			0						//前排左边首个电感，横
#define BL2			1						//前排左边次个电感，竖
#define BL3			2						//单排左边第三个电感，斜
#define BCTR		3						//前排中间电感，横
#define BR1			4						//前排右边首个电感，横
#define BR2 		5						//前排右边次个电感，竖
#define BR3			6						//前排右边第三个电感，斜




#define ELC_NUM 	7   		//电感总数
#define ELC_GROUP   3      	//采集组数
#define ELC_TIME    3				//每组的采集次数
#define ELC_NEED    1       //排序完后的所需值

//#define ELC_MAX_CENTER_ERROR  130

//电感值
extern uint16	edata LNow[7];//原始值
extern uint16	edata LNor[7];//归一化的数值
////归一化零偏值
extern uint16  edata ELC[ELC_GROUP][ELC_TIME][ELC_NUM];
extern uint8 left_value;
extern uint8 right_value;
extern int16 ad_sum; 
extern int16 ad_diff; 
extern int16 deviation; 
extern uint8 ElcProtect_Flag;		

void My_center_mag(uint8 i);
////function
//void 	Inductor_Init(void);
void InductorRead(void);
void SimpleNorRead(void);
//void	CenterCalculate(void);

#endif