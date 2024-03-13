#include "vofa.h"
union
{
    unsigned char a[4];   //在单片机中浮点存储为大端模式，高字节在低位，低字节在高位。
    float b;

} temp;
unsigned char tail[4] = {0x00, 0x00, 0x80, 0x7f};   //结尾
//int16 duty = 2000;
//=============================自定义函数区间===================================
void showData(float dat)         //vofa打印数据用这个
{
    int i;
    temp.b = dat;
    for( i = 3; i >= 0; i-- )          //发送浮点数 小端模式发送
	//wireless_uart_send_char(temp.a[i]);
		uart_putchar(DEBUG_UART,temp.a[i]);
}
//-----------------------------------------------------------------------------------
//发送结尾协议-------------------------------------------------------------
void showTail(void)
{
    int i;
    for( i = 0; i < 4; i++ )            //发送结尾
	//wireless_uart_send_char(tail[i]);
	uart_putchar(DEBUG_UART,tail[i]);
}