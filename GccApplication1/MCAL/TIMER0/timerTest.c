/*
 * timerTest.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */

#include "TIMER_0.h"
#include "../../ECU/LED/LED.h"


ST_timer0_t tmr0 =
{
	.mode = TIMER0_NOTMAL_MODE,
	.ocMode = OCO_DISCONNECTED,
	.prescaller = TIMER0_8_PRESCALER
};


ST_led_t led =
{
	.port = PORTD_INDEX,
	.pin = GPIO_PIN0,
	.status = LED_OFF
};

int timerTest(void)
{
	TMR0_init(&tmr0);
	Led_Init(&led);
	
	while(1)
	{
		Led_Toggle(&led);
		
		TMR0_Write_Value(56);
		for(uint16 i=0 ; i<5000 ; i++)
		{
			while(TCNT0);
			TMR0_Write_Value(56);
		}
	}
}

