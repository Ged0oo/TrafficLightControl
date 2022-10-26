/*
 * externalInterruptTest.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */ 



#include "EXTERNAL_INTERRUPT.h"
#include "../../ECU/LED/LED.h"
void ext0Handeler();


ST_led_t led_0 =
{
	.port = PORTD_INDEX,
	.pin = GPIO_PIN0,
	.status = LED_OFF
};

void ext0Handeler()
{
	Led_Toggle(&led_0);
}

ST_externalInterrupt_t ext_0 = 
{
	.edge = EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE,
	.source = EXI_INT0,
	.INT0_fpt = ext0Handeler  
};



void externalInterruptTest()
{
	sei();
	
	EXI_interrupt_init(&ext_0);
	EXI_CallBack(&ext_0);
	
	Led_Init(&led_0);
	
	while(1);
}
