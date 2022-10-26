/*
 * LED.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */



#include "LED.h"



/**
 * 
 * @param led Pointer to the LED configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Led_Init(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_pin_dirction_init(&led_1);
		ret = gpio_write_logic(&led_1, GPIO_LOW);
	}
	return ret;
}



/**
 * 
 * @param led Pointer to the LED configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Led_Turn_On(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_write_logic(&led_1, GPIO_HIGH);
	}
	return ret;
}



/**
 * 
 * @param led Pointer to the LED configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Led_Turn_Off(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_write_logic(&led_1, GPIO_LOW);
	}
	return ret;
}



/**
 * 
 * @param led Pointer to the LED configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Led_Toggle(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = GPIO_DIRECTION_OUTPUT
		};
		ret = gpio_pin_toggle(&led_1);
	}
	return ret;
}


/**
 * 
 * @param led Pointer to the LED configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Led_Blink_aSecond(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		
		TCCR2 = TCCR2 | 0X02;
		
		TCNT2 = 56;
		
		for(uint16 i=0 ; i<25000 ; i++)
		{
			while(TCNT2);
			TCNT2 = 56;
			if(i%2500 == 0)
			{
				Led_Toggle(led);
			}
		}
	}
	return ret;
}



EN_ledStatus_t Led_State(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		return led->status;
	}
}


Std_ReturnType Two_Led_Blink_aSecond(const ST_led_t* led_1, const ST_led_t* led_2)
{
	Std_ReturnType ret = E_OK;
	if(led_1 == NULL || led_2 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		
		TCCR2 = TCCR2 | 0X02;
		
		TCNT2 = 56;
		
		for(uint16 i=0 ; i<25000 ; i++)
		{
			while(TCNT2);
			TCNT2 = 56;
			if(i%2500 == 0)
			{
				Led_Toggle(led_1);
				Led_Toggle(led_2);
			}
		}
	}
	return ret;
}
