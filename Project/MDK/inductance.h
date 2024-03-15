#ifndef _INDUCTANCE_H_
#define _INDUCTANCE_H_
#include "headfile.h"
#define BL1			0						//ǰ������׸���У���
#define BL2			1						//ǰ����ߴθ���У���
#define BL3			2						//������ߵ�������У�б
#define BCTR		3						//ǰ���м��У���
#define BR1			4						//ǰ���ұ��׸���У���
#define BR2 		5						//ǰ���ұߴθ���У���
#define BR3			6						//ǰ���ұߵ�������У�б




#define ELC_NUM 	7   		//�������
#define ELC_GROUP   3      	//�ɼ�����
#define ELC_TIME    3				//ÿ��Ĳɼ�����
#define ELC_NEED    1       //������������ֵ

//#define ELC_MAX_CENTER_ERROR  130

//���ֵ
extern uint16	edata LNow[7];//ԭʼֵ
extern uint16	edata LNor[7];//��һ������ֵ
////��һ����ƫֵ
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