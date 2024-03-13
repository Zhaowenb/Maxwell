/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC32G12K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"


/*
 * 系统频率，可查看board.h中的 FOSC 宏定义修改。
 * board.h文件中FOSC的值设置为0,则程序自动设置系统频率为33.1776MHZ
 * 在board_init中,已经将P54引脚设置为复位
 * 如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */


void main()
{
			//float out_dw;
	All_init();
	// 此处编写用户代码(例如：外设初始化代码等)
	
    while(1)
	{
		 // 此处编写需要循环执行的代码
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
		
//		ips114_showfloat(0,20,LNow[1],5,0);//左2电感
//		ips114_showfloat(50,20,LNow[2],5,0);
//		ips114_showfloat(140,20,LNow[3],5,0);//中间电感
//		ips114_showfloat(0,70,LNow[4],5,0);//右1电感
//		ips114_showfloat(50,70,LNow[5],5,0);//右2电感
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
		ips114_showfloat(0,20,LNor[BL1],5,0);//左2电感
		ips114_showfloat(50,20,LNor[BL2],5,0);
		ips114_showfloat(140,20,LNor[BL3],5,0);//中间电感
		ips114_showfloat(0,70,LNor[BR1],5,0);//右1电感
		ips114_showfloat(50,70,LNor[BR2],5,0);//右2电感
		ips114_showfloat(140,70,LNor[BR3],5,0);
    }
}

