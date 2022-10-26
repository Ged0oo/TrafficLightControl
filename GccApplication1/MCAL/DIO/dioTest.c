/*
 * dioTest.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */


#include "DIO.h"

ST_pinCofig_t pin1 =
{
	.pin = GPIO_PIN0,
	.port = PORTB_INDEX,
	.pin_logic = GPIO_HIGH,
	.pin_direction = GPIO_DIRECTION_OUTPUT
};

void dioTest()
{
	gpio_pin_init(&pin1);
	gpio_write_logic(&pin1, GPIO_LOW);
}
