#include "All_init.h"

void All_init(void)
{	
	DisableGlobalIRQ();
	board_init();			// 初始化寄存器,勿删除此句代码。
		EnableGlobalIRQ();
	Screen_init();
	//wireless_uart_init();
	//gyro_init();
	//imu_offset();

	uart_init(UART_3,UART3_RX_P50, UART3_TX_P51,115200,TIM_3);//打开有线串口
	PID_ALL_Init();   
	Motor_init(); 
	//Beep_init();
	//Key_init();
	Encoder_init();
	//imu660ra_init();
	//Adcs_init();
	
	
	pit_timer_ms(TIM_2,1);//进中断
//	ips114_showstr(0,20,"-LinYuan-");
//	ips114_showstr(0,70,"Initialization Succeeded.");
//	Beep_bee();
}