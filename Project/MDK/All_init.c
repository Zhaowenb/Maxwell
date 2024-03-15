#include "All_init.h"

void All_init(void)
{	
	DisableGlobalIRQ();
	board_init();	
EnableGlobalIRQ();	// 初始化寄存器,勿删除此句代码。
	Screen_init();
	Adcs_init();
	//wireless_uart_init();
	//gyro_init();
	//imu_offset();
	PID_ALL_Init();   
	Motor_init(); 
	Beep_init();
	Key_init();
	Encoder_init();
//	EnableGlobalIRQ();
	//imu660ra_init();
	
	pit_timer_ms(TIM_4,1);//进中断
//	ips114_showstr(0,20,"-LinYuan-");
//	ips114_showstr(0,70,"Initialization Succeeded.");
//Beep_bee();
}