#include "vofa.h"
union
{
    unsigned char a[4];   //�ڵ�Ƭ���и���洢Ϊ���ģʽ�����ֽ��ڵ�λ�����ֽ��ڸ�λ��
    float b;

} temp;
unsigned char tail[4] = {0x00, 0x00, 0x80, 0x7f};   //��β
//int16 duty = 2000;
//=============================�Զ��庯������===================================
void showData(float dat)         //vofa��ӡ���������
{
    int i;
    temp.b = dat;
    for( i = 3; i >= 0; i-- )          //���͸����� С��ģʽ����
	//wireless_uart_send_char(temp.a[i]);
		uart_putchar(DEBUG_UART,temp.a[i]);
}
//-----------------------------------------------------------------------------------
//���ͽ�βЭ��-------------------------------------------------------------
void showTail(void)
{
    int i;
    for( i = 0; i < 4; i++ )            //���ͽ�β
	//wireless_uart_send_char(tail[i]);
	uart_putchar(DEBUG_UART,tail[i]);
}