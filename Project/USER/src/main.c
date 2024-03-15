/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * ϵͳƵ�ʣ��ɲ鿴board.h�е� FOSC �궨���޸ġ�
 * board.h�ļ���FOSC��ֵ����Ϊ0,������Զ�����ϵͳƵ��Ϊ33.1776MHZ
 * ��board_init��,�Ѿ���P54��������Ϊ��λ
 * �����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */


void main()
{
	All_init();
//	PidI_L.Kp = 1;
//	PidI_R.Kp = 1;
//	PidI_L.Ki = 0.3;
//	PidI_R.Ki = 0.3;
//	PidI_L.Kd = 0.4;
//	PidI_R.Kd = 0.4;
//	adc_once(ADC_BL1,ADC_12BIT);
    while(1)
	{
//		Key_Scan();
//		Key_Screen();
		ips114_showfloat(100,0,left_value,5,0);
		ips114_showfloat(140,0,right_value,5,0);

		ips114_showfloat(0,0,LNor[BCTR],5,0);
		ips114_showfloat(0,20,LNor[BL1],5,0);
		ips114_showfloat(50,20,LNor[BL2],5,0);
		ips114_showfloat(140,20,LNor[BL3],5,0);
		ips114_showfloat(0,70,LNor[BR1],5,0);
		ips114_showfloat(50,70,LNor[BR2],5,0);
		ips114_showfloat(140,70,LNor[BR3],5,0);
    }
}

