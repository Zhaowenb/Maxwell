#include "Beep.h"
void Beep_init(void)
{
	gpio_mode(BEEP,GPO_PP);     //�����������
	gpio_pull_set(BEEP,NOPULL); //���ò�������
	beep = 0;
}
void Beep_bee(void)
{
	beep = 1;
	delay_ms(100);
	beep = 0;
	delay_ms(100);
}