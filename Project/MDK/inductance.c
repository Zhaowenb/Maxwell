#include "headfile.h"
#include <math.h>
#define ELC_NUM 	7   		//�������
#define ELC_GROUP   3      	//�ɼ�����
#define ELC_TIME    3				//ÿ��Ĳɼ�����
#define ELC_NEED    1       //������������ֵ
//�ɼ�����ֵ
uint16	edata LNow[7];																															//ԭʼֵ�˲���
uint16	edata LNor[7];																																//��һ������ֵ
uint16	edata LNowMax[7] = {3740,3740,3740,3740,3740,3740,3740};																							//���µ���
uint16	edata LNowMin[7] = {0,0,0,0,0,0,0};																							//���µ���
uint16  edata ELC[ELC_GROUP][ELC_TIME][ELC_NUM];																		//��вɼ�ֵ

uint8 left_value;
uint8 right_value;
int16 ad_sum; 
int16 ad_diff; 
int16 deviation; 
//�Ҽ����:R+L
uint16	edata ELC_Sum_F00 = 0;
uint16	edata ELC_Sum_F11 = 0;
uint16	edata ELC_Sum_F0110 = 0;
uint16	edata ELC_Sum_FALL = 0;

//�Ҽ����:R-L
int16	edata ELC_Err_F00 = 0;
int16	edata ELC_Err_F11 = 0;
int16	edata ELC_Err_B00 = 0;

//����ƫ��
int16   edata ELC_Center = 0;																												//����ƫ��
int16	edata ELC_CenterLast = 0;																											//��һ������ƫ��
int16	edata ELC_CenterBefore = 0; 																									//���ϴ�����ƫ��
int16	edata ELC_CenterRepair = 0; 																									//�����������ƫ��
int16	edata ELC_Center_F00 =  0;  																									//F00ƫ��
int16	edata ELC_Center_F11 =  0;																										//F11ƫ��
//int16	edata ELC_Center_F0110 = 0; 																								//F00��F11ƫ��
int16	edata ELC_Center_B00 = 0;   																									//B00ƫ��

//��־λ
uint8	ElcProtect_Flag=0;																														//��б�����־λ�������ܵ��Զ�ֹͣ
uint8	edata ELC_Center_Flag = 0;
/////*
////@brief	��г�ʼ��,��ȡ��������ֵ,�����й�һ����ƫֵ�ĳ�ʼ��,����ʾ����Ļ��,�����м����й�һ����ƫֵ������,����ʾ����Ļ��,��������EEPROM��.
////@param	void
////@return	void
////@since	v0.1.0
////@Sample usage: Inductor_Init();
////@note	��
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
//////	//��ȡ��������ֵ
//////	while(KeyLast != onepress)
//////	{
//////		//��ȡ��������ֵ
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
//////		//�����м����й�һ����ƫֵ������
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
//////		//δ�����м�,��ʾ��һ����ƫֵ
//////		else {
//////			IPS114_PENCOLOR = BLUE;
//////			ips114_showuint8(8  ,7,ELC_OffSet_F00);
//////			ips114_showuint8(54 ,7,ELC_OffSet_F11);
//////			ips114_showuint8(100 ,7,ELC_OffSet_B00);
//////			ips114_showuint8(146,7,ELC_OffSet_FC);
//////			ips114_showuint8(190,7,ELC_OffSet_BC);
//////		}
//////	}
//////	//�ɿ�����������
//////	KeyLast = nopress;
//////	ips114_clear(YELLOW);
////}

/*
@brief	��ж�ȡ,��ȡ���ֵ,����������,��һ��,���������Һ�,���Ҳ�,����ƫ��,����������ƫ�������,����������ƫ����˲�.
@param	void
@return	void
@since	v0.1.0
@Sample usage: InductorRead();
@note	��
*/
void InductorRead(void)
{
	uint16 L_sum[ELC_NUM] = {0,0,0,0,0,0,0};
	uint8 i = 0,j = 0,k = 0;
	uint16  L_max = 0,L_max_index = 0,len = 0;
	
	//��ȡ��·���ֵ
	for(i = 0;i < ELC_GROUP;i ++)
	{
		for(j = 0;j < ELC_TIME;j ++)
		{
			//��ȡ��·���ֵ
			ELC[i][j][0] = adc_once(ADC_BL1,ADC_12BIT);//ǰ������׸����
			ELC[i][j][1] = adc_once(ADC_BL2,ADC_12BIT);//ǰ����ߴθ����
			ELC[i][j][2] = adc_once(ADC_BL3,ADC_12BIT);//ǰ����ߵ��������
			ELC[i][j][3] = adc_once(ADC_BCTR,ADC_12BIT); //ǰ���м���
			ELC[i][j][4] = adc_once(ADC_BR1,ADC_12BIT);//ǰ���ұ��׸����
			ELC[i][j][5] = adc_once(ADC_BR2,ADC_12BIT);//ǰ���ұ��׸����
			ELC[i][j][6] = adc_once(ADC_BR3,ADC_12BIT);//ǰ���ұߵ��������
		}
	}
	//ð������ ��·���ֵ
	for(i = 0;i < ELC_GROUP;i ++)									 		//���е��鶼��Ҫ����
	{
		for(k = 0;k < ELC_NUM;k ++)											//ÿ����к���������
		{
			len = ELC_TIME;
			while(len > 1)																//����ֻʣ��һ��Ԫ�غ��ٽ�������
			{
				L_max = 0;
				L_max_index = 0;
				for(j = 0;j < len;j ++)
				{
					if(ELC[i][j][k] > L_max)
					{
						L_max = ELC[i][j][k];										//��¼���ֵ
						L_max_index = j;												//��¼���ֵ�±�
					}
				}
				ELC[i][L_max_index][k] = ELC[i][len - 1][k];//��������
				ELC[i][len - 1][k] = L_max;									//���ֵ����
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
@brief	�򵥹�һ��
@param	void
@return	void
@since	v0.1.0
@Sample usage: SimpleNorRead();
@note	����Ϊ0����������м���
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
//@brief	���߼���,���߼���ķ���������,һ����F00��B00��ͬ,F11��B00�෴,һ����F00��B00�෴,F11��B00��ͬ,���߼���ķ���������,һ����F00��B00��ͬ,F11��B00�෴,һ����F00��B00�෴,F11��B00��ͬ
//@param	void
//@return	void
//@since	v0.1.0
//@Sample usage: CenterCalculate();
//@note	��
//*/
//void CenterCalculate(void)
//{
//	
//}
//���������ж�
void My_center_mag(uint8 i)
{
// ����������ֵ
	left_value  = limit_ab(sqrt(LNor[BL1]  * LNor[BL1]  + LNor[BL2] * LNor[BL2] ), 0, 100);
	right_value = limit_ab(sqrt(LNor[BR1]* LNor[BR1] + LNor[BR2] * LNor[BR2]), 0, 100);
	// ������֮�� 
	ad_sum= left_value + right_value;         
	// ������֮��
  ad_diff= (int16) left_value - right_value; 
	if(ad_sum>20)                                     	// �߽籣�� 
	{ 
		ElcProtect_Flag = 'T';
		if(i)
// ����һ 
			{
				deviation = (ad_diff * 100) / (ad_sum + 1);		// �����Ⱥ���ֵ ���Ŵ�һ�ٱ� 
			}
// ������ 
		else deviation = (ad_diff << 7 ) / (ad_sum + 1); 	// �����Ⱥ���ֵ ���Ŵ�128�� 
	} 
	else
	{
		ElcProtect_Flag = 'F';	
	}
}                     
//��Ⱥ������б�
/*
@brief	���߼���,���߼���ķ���������,һ����F00��B00��ͬ,F11��B00�෴,һ����F00��B00�෴,F11��B00��ͬ,���߼���ķ���������,һ����F00��B00��ͬ,F11��B00�෴,һ����F00��B00�෴,F11��B00��ͬ
@param	void
@return	void
@since	v0.1.0
@Sample usage: CenterCalculate();
@note	��
*/
//void My_CenterCalculate(void)
//{
//	ELC_Sum_F00 = LNor[BR1] + LNor[BL1];							//���ҵ�к�
//	ELC_Sum_F11 = LNor[BR2] + LNor[BL2];							//�м�����к�
//	ELC_Sum_F0110 = ELC_Sum_F00 + ELC_Sum_F11;				//F00��F11��к�
//	ELC_Sum_FALL = ELC_Sum_F0110 + LNor[BCTR];					//F00��F11��FC��к�
//	//�Ҽ����
//	ELC_Err_F00 = LNor[BL1] - LNor[BR1];							//���ҵ�в�
//	ELC_Err_F11 = LNor[BL2] - LNor[BR2];							//�м�����в�
//	//�ܳ��ܵ��ж�
//	if(ELC_Sum_FALL <= 30)	ElcProtect_Flag = 'T';		//��б�����־λ��δ�����ܵ���������
//	else ElcProtect_Flag = 'F';												//��б�����־λ�������ܵ��Զ�ֹͣ
//	ELC_Center_F00 = (int16)((float)ELC_Err_F00 * 200.0f/((float)ELC_Sum_F00 + (float)LNor[BCTR]));
//	ELC_Center_F11 = (int16)((float)ELC_Err_F11 * 200.0f/((float)ELC_Sum_F11 + (float)LNor[BCTR]));                  

//}


