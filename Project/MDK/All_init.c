#include "All_init.h"

void All_init(void)
{	
	//DisableGlobalIRQ();
	board_init();			// ��ʼ���Ĵ���,��ɾ���˾���롣
	Screen_init();
	//wireless_uart_init();
	//gyro_init();
	//imu_offset();
	PID_ALL_Init();   
	Motor_init(); 
	Beep_init();
	Key_init();
	Encoder_init();
	//imu660ra_init();
	Adcs_init();
	//EnableGlobalIRQ();
	pit_timer_ms(TIM_2,1);//���ж�
//	ips114_showstr(0,20,"-LinYuan-");
//	ips114_showstr(0,70,"Initialization Succeeded.");
//	Beep_bee();
}