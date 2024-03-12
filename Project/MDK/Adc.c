#include "Adc.h"
//float BL1,BL2,BL3,BCTR,BR1,BR2,BR3;
void Adcs_init(void)
{
//	adc_init(ADC_P10,ADC_SYSclk_DIV_2);
//	adc_init(ADC_P00,ADC_SYSclk_DIV_2);
//	adc_init(ADC_P01,ADC_SYSclk_DIV_2);
//	adc_init(ADC_P02,ADC_SYSclk_DIV_2);
	adc_init(ADC_P03,ADC_SYSclk_DIV_2);
	adc_init(ADC_P04,ADC_SYSclk_DIV_2);
//	adc_init(ADC_P05,ADC_SYSclk_DIV_2);
	adc_init(ADC_P06,ADC_SYSclk_DIV_2);
	adc_init(ADC_P11,ADC_SYSclk_DIV_2);
	adc_init(ADC_P13,ADC_SYSclk_DIV_2);
	adc_init(ADC_P14,ADC_SYSclk_DIV_2);
//	adc_init(ADC_P15,ADC_SYSclk_DIV_2);
	adc_init(ADC_P16,ADC_SYSclk_DIV_2);
}
//void Adcs_read(void)
//{
//	BCTR = adc_once(ADC_BCTR,ADC_12BIT);
//	BL1 = adc_once(ADC_BL1,ADC_12BIT);
//	BL2 = adc_once(ADC_BL2,ADC_12BIT);
//	BL3 = adc_once(ADC_BL3,ADC_12BIT);
//	BR1 = adc_once(ADC_BR1,ADC_12BIT);
//	BR2 = adc_once(ADC_BR2,ADC_12BIT);
//	BR3 = adc_once(ADC_BR3,ADC_12BIT);
////Beep_bee();
//}