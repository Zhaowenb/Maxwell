#include "Encoder.h"

void Encoder_init(void)
{
	ctimer_count_init(left_encoder);//×ó±àÂëÆ÷
	ctimer_count_init(right_encoder);//ÓÒ±àÂëÆ÷
}
void Encoder_speed(void)
{
	PidI_L.real = ctimer_count_read(left_encoder);
	PidI_R.real = ctimer_count_read(right_encoder);
	ctimer_count_clean(left_encoder);
	ctimer_count_clean(right_encoder);
}