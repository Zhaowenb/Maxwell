#ifndef __ADC_H_
#define __ADC_H_
#include "headfile.h"
//extern float BL1,BL2,BL3,BCTR,BR1,BR2,BR3;
#define ADC_BL3			ADC_P06
#define ADC_BCTR		ADC_P03
#define ADC_BL1			ADC_P11
#define ADC_BL2			ADC_P13
#define ADC_BR1			ADC_P16
#define ADC_BR2			ADC_P14
#define ADC_BR3			ADC_P04
//#define ADC_BL3			ADC_P03
//#define ADC_BCTR		ADC_P11
//#define ADC_BL1			ADC_P13
//#define ADC_BL2			ADC_P06
//#define ADC_BR1			ADC_P16
//#define ADC_BR2			ADC_P14
//#define ADC_BR3			ADC_P04
void Adcs_init(void);
//void Adcs_read(void);
#endif
