#include "headfile.h"
#include <math.h>
#define ELC_NUM 	7   		//电感总数
#define ELC_GROUP   3      	//采集组数
#define ELC_TIME    3				//每组的采集次数
#define ELC_NEED    1       //排序完后的所需值
//采集数据值
uint16	edata LNow[7];																															//原始值滤波后
uint16	edata LNor[7];																																//归一化的数值
uint16	edata LNowMax[7] = {3740,3740,3740,3740,3740,3740,3740};																							//重新调整
uint16	edata LNowMin[7] = {0,0,0,0,0,0,0};																							//重新调整
uint16  edata ELC[ELC_GROUP][ELC_TIME][ELC_NUM];																		//电感采集值

uint8 left_value;
uint8 right_value;
int16 ad_sum; 
int16 ad_diff; 
int16 deviation; 
//右加左和:R+L
uint16	edata ELC_Sum_F00 = 0;
uint16	edata ELC_Sum_F11 = 0;
uint16	edata ELC_Sum_F0110 = 0;
uint16	edata ELC_Sum_FALL = 0;

//右减左差:R-L
int16	edata ELC_Err_F00 = 0;
int16	edata ELC_Err_F11 = 0;
int16	edata ELC_Err_B00 = 0;

//中线偏差
int16   edata ELC_Center = 0;																												//中线偏差
int16	edata ELC_CenterLast = 0;																											//上一次中线偏差
int16	edata ELC_CenterBefore = 0; 																									//上上次中线偏差
int16	edata ELC_CenterRepair = 0; 																									//修正后的中线偏差
int16	edata ELC_Center_F00 =  0;  																									//F00偏差
int16	edata ELC_Center_F11 =  0;																										//F11偏差
//int16	edata ELC_Center_F0110 = 0; 																								//F00和F11偏差
int16	edata ELC_Center_B00 = 0;   																									//B00偏差

//标志位
uint8	ElcProtect_Flag=0;																														//电感保护标志位：超出跑道自动停止
uint8	edata ELC_Center_Flag = 0;
/////*
////@brief	电感初始化,获取各电感最大值,并进行归一化零偏值的初始化,并显示在屏幕上,按下中键进行归一化零偏值的设置,并显示在屏幕上,并保存在EEPROM中.
////@param	void
////@return	void
////@since	v0.1.0
////@Sample usage: Inductor_Init();
////@note	无
////*/
////void Inductor_Init(void)
////{
//////	uint8 i = 0;
//////	vuint8 ClosedLoopMode_Temp = (uint8)CarInfo.ClosedLoopMode;
//////	CarInfo.ClosedLoopMode = NoLoop;
//////	ips114_clear(YELLOW);
//////	IPS114_PENCOLOR = RED;
//////	for(i = 0; i < ELC_NUM; i++)
//////		LNowMax[i] = 0;
//////	ips114_showstr(0,0,"ELC_NowMax_Initializing...");
//////	ips114_showstr(0,5,"Press_Center_to_Offset...");
//////	IPS114_PENCOLOR = BLUE;
//////	ips114_showstr(0,1,"  FL1   FL0   FC   FR0   FR1  ");
//////	//获取各电感最大值
//////	while(KeyLast != onepress)
//////	{
//////		//获取各电感最大值
//////		for(i = 0; i < ELC_NUM; i++)
//////		{
//////			if(LNow[i] > LNowMax[i]){
//////				LNowMax[i] = LNow[i];
//////				IPS114_PENCOLOR = RED;
//////				if(i < 5) ips114_showuint16(i*46,2,LNowMax[i]);
//////				else ips114_showuint16(i*92,4,LNowMax[i]);
//////			}
//////			else {
//////				IPS114_PENCOLOR = BLUE;
//////				if(i < 5) ips114_showuint16(i*46,2,LNowMax[i]);
//////				else ips114_showuint16((i-5)*92,4,LNowMax[i]);
//////			}
//////		}
//////		//按下中键进行归一化零偏值的设置
//////		if(KeyCenter == onepress){
//////			KeyCenter = nopress;
//////			ELC_OffSet_F00 = (LNor[FL0] + LNor[FR0])/2;  
//////			ELC_OffSet_F11 = (LNor[FL1] + LNor[FR1])/2;
//////			ELC_OffSet_FC = LNor[FC];
//////			ELC_OffSet_B00 = (LNor[BL0] + LNor[BR0])/2;
//////			ELC_OffSet_BC = LNor[BC];
//////			IPS114_PENCOLOR = RED;
//////			ips114_showuint8(0  ,7,ELC_OffSet_F00);
//////			ips114_showuint8(46 ,7,ELC_OffSet_F11);
//////			ips114_showuint8(92 ,7,ELC_OffSet_B00);
//////			ips114_showuint8(138,7,ELC_OffSet_FC);
//////			ips114_showuint8(184,7,ELC_OffSet_BC);
//////		}
//////		//未按下中键,显示归一化零偏值
//////		else {
//////			IPS114_PENCOLOR = BLUE;
//////			ips114_showuint8(8  ,7,ELC_OffSet_F00);
//////			ips114_showuint8(54 ,7,ELC_OffSet_F11);
//////			ips114_showuint8(100 ,7,ELC_OffSet_B00);
//////			ips114_showuint8(146,7,ELC_OffSet_FC);
//////			ips114_showuint8(190,7,ELC_OffSet_BC);
//////		}
//////	}
//////	//松开按键，清屏
//////	KeyLast = nopress;
//////	ips114_clear(YELLOW);
////}

/*
@brief	电感读取,获取电感值,并进行排序,归一化,并计算左右和,左右差,中线偏差,并进行中线偏差的修正,并进行中线偏差的滤波.
@param	void
@return	void
@since	v0.1.0
@Sample usage: InductorRead();
@note	无
*/
void InductorRead(void)
{
	uint16 L_sum[ELC_NUM] = {0,0,0,0,0,0,0};
	uint8 i = 0,j = 0,k = 0;
	uint16  L_max = 0,L_max_index = 0,len = 0;
	
	//获取七路电感值
	for(i = 0;i < ELC_GROUP;i ++)
	{
		for(j = 0;j < ELC_TIME;j ++)
		{
			//获取七路电感值
			ELC[i][j][0] = adc_once(ADC_BL1,ADC_12BIT);//前排左边首个电感
			ELC[i][j][1] = adc_once(ADC_BL2,ADC_12BIT);//前排左边次个电感
			ELC[i][j][2] = adc_once(ADC_BL3,ADC_12BIT);//前排左边第三个电感
			ELC[i][j][3] = adc_once(ADC_BCTR,ADC_12BIT); //前排中间电感
			ELC[i][j][4] = adc_once(ADC_BR1,ADC_12BIT);//前排右边首个电感
			ELC[i][j][5] = adc_once(ADC_BR2,ADC_12BIT);//前排右边首个电感
			ELC[i][j][6] = adc_once(ADC_BR3,ADC_12BIT);//前排右边第三个电感
		}
	}
	//冒泡排序 七路电感值
	for(i = 0;i < ELC_GROUP;i ++)									 		//所有的组都需要排序
	{
		for(k = 0;k < ELC_NUM;k ++)											//每个电感号组内排序
		{
			len = ELC_TIME;
			while(len > 1)																//排序到只剩下一个元素后不再进行排序
			{
				L_max = 0;
				L_max_index = 0;
				for(j = 0;j < len;j ++)
				{
					if(ELC[i][j][k] > L_max)
					{
						L_max = ELC[i][j][k];										//记录最大值
						L_max_index = j;												//记录最大值下标
					}
				}
				ELC[i][L_max_index][k] = ELC[i][len - 1][k];//交换数据
				ELC[i][len - 1][k] = L_max;									//最大值后移
				len --;
			}
			L_sum[k] += ELC[i][ELC_NEED][k];
		}
	}
	for(i = 0;i < ELC_NUM;i ++)
	{
		LNow[i] = L_sum[i]/ELC_GROUP;
	}
}

/*
@brief	简单归一化
@param	void
@return	void
@since	v0.1.0
@Sample usage: SimpleNorRead();
@note	输入为0，不会调用中间电感
*/
void SimpleNorRead(void)
{
	uint8 i=0;
	for(i=0;i<ELC_NUM;i++)
	{
		LNor[i] = (uint16)(((float)(LNow[i]-LNowMin[i] )* 100.0f)/(float)(LNowMax[i]-LNowMin[i]));
	}
}


///*
//@brief	中线计算,中线计算的方法有两种,一种是F00和B00相同,F11和B00相反,一种是F00和B00相反,F11和B00相同,中线计算的方法有两种,一种是F00和B00相同,F11和B00相反,一种是F00和B00相反,F11和B00相同
//@param	void
//@return	void
//@since	v0.1.0
//@Sample usage: CenterCalculate();
//@note	无
//*/
//void CenterCalculate(void)
//{
//	
//}
//向量中线判断
void My_center_mag(uint8 i)
{
// 计算电感向量值
	left_value  = limit_ab(sqrt(LNor[BL1]  * LNor[BL1]  + LNor[BL2] * LNor[BL2] ), 0, 100);
	right_value = limit_ab(sqrt(LNor[BR1]* LNor[BR1] + LNor[BR2] * LNor[BR2]), 0, 100);
	// 计算电感之和 
	ad_sum= left_value + right_value;         
	// 计算电感之差
  ad_diff= (int16) left_value - right_value; 
	if(ad_sum>20)                                     	// 边界保护 
	{ 
		ElcProtect_Flag = 'T';
		if(i)
// 方法一 
			{
				deviation = (ad_diff * 100) / (ad_sum + 1);		// 计算差比和数值 并放大一百倍 
			}
// 方法二 
		else deviation = (ad_diff << 7 ) / (ad_sum + 1); 	// 计算差比和数值 并放大128倍 
	} 
	else
	{
		ElcProtect_Flag = 'F';	
	}
}                     
//差比和中线判别
/*
@brief	中线计算,中线计算的方法有两种,一种是F00和B00相同,F11和B00相反,一种是F00和B00相反,F11和B00相同,中线计算的方法有两种,一种是F00和B00相同,F11和B00相反,一种是F00和B00相反,F11和B00相同
@param	void
@return	void
@since	v0.1.0
@Sample usage: CenterCalculate();
@note	无
*/
//void My_CenterCalculate(void)
//{
//	ELC_Sum_F00 = LNor[BR1] + LNor[BL1];							//左右电感和
//	ELC_Sum_F11 = LNor[BR2] + LNor[BL2];							//中间两电感和
//	ELC_Sum_F0110 = ELC_Sum_F00 + ELC_Sum_F11;				//F00和F11电感和
//	ELC_Sum_FALL = ELC_Sum_F0110 + LNor[BCTR];					//F00和F11和FC电感和
//	//右减左差
//	ELC_Err_F00 = LNor[BL1] - LNor[BR1];							//左右电感差
//	ELC_Err_F11 = LNor[BL2] - LNor[BR2];							//中间两电感差
//	//跑出跑道判断
//	if(ELC_Sum_FALL <= 30)	ElcProtect_Flag = 'T';		//电感保护标志位，未超出跑道无需在意
//	else ElcProtect_Flag = 'F';												//电感保护标志位，超出跑道自动停止
//	ELC_Center_F00 = (int16)((float)ELC_Err_F00 * 200.0f/((float)ELC_Sum_F00 + (float)LNor[BCTR]));
//	ELC_Center_F11 = (int16)((float)ELC_Err_F11 * 200.0f/((float)ELC_Sum_F11 + (float)LNor[BCTR]));                  

//}


