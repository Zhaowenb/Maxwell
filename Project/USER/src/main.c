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
			//float out_dw;
	All_init();
	// �˴���д�û�����(���磺�����ʼ�������)
	
    while(1)
	{
		 // �˴���д��Ҫѭ��ִ�еĴ���
//		Key_Scan();
//		Key_Screen();
		//InductorRead();
//		InductorRead();
//		SimpleNorRead();
//		SimpleNorRead();
//		Encoder_speed();
//		if(PidI_L.real!=0)
//		{
//			Beep_bee();
//		}
		//ips114_clear(YELLOW);
		
//	ips114_showfloat(0,0,PidI_L.last_out,5,0);
//	ips114_showfloat(50,0,PidI_R.last_out,5,0);
		
//		ips114_showfloat(0,20,LNow[1],5,0);//��2���
//		ips114_showfloat(50,20,LNow[2],5,0);
//		ips114_showfloat(140,20,LNow[3],5,0);//�м���
//		ips114_showfloat(0,70,LNow[4],5,0);//��1���
//		ips114_showfloat(50,70,LNow[5],5,0);//��2���
//		ips114_showfloat(140,70,LNow[6],5,0);

//		PidSpeed_Ctrl();
//		showData(PidI_L.last_out);
//		showData(PidI_R.last_out);
//		showTail();
//		
//		ips114_showfloat(100,0,left_value,5,0);
//		ips114_showfloat(140,0,right_value,5,0);
//		
		ips114_showfloat(0,0,LNor[BCTR],5,0);
		ips114_showfloat(0,20,LNor[BL1],5,0);//��2���
		ips114_showfloat(50,20,LNor[BL2],5,0);
		ips114_showfloat(140,20,LNor[BL3],5,0);//�м���
		ips114_showfloat(0,70,LNor[BR1],5,0);//��1���
		ips114_showfloat(50,70,LNor[BR2],5,0);//��2���
		ips114_showfloat(140,70,LNor[BR3],5,0);
    }
}

