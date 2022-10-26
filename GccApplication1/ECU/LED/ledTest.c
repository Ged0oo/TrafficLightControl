/*
 * ledTest.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */


#include "LED.h"

ST_led_t led1 =
{
	.port = PORTD_INDEX,
	.pin = GPIO_PIN0,
	.status = LED_OFF
};

void ledTest()
{
	Led_Init(&led1);
	while(1)
	{
		//Led_Turn_Off(&led1);
		//Led_Turn_On(&led1);
		Led_Toggle(&led1);
	}
}
