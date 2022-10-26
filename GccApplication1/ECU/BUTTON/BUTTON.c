/*
 * BUTTON.c
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */


#include "BUTTON.h"



/**
 * 
 * @param button Pointer to the BUTTON configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Button_init(const ST_buton_t* button)
{
	Std_ReturnType ret = E_OK;
	if(button == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		gpio_pin_dirction_init(&(button->pin));
	}
	return ret;
}



/**
 * 
 * @param button Pointer to the BUTTON configurations
 * @param state Pointer to the BUTTON STATE configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType Button_read_status(const ST_buton_t* button, EN_buttonState* state)
{
	Std_ReturnType ret = E_OK;
	EN_logic_t Pin_Logic_Status = GPIO_LOW;
	
	if(button==NULL || state==NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		gpio_read_logic(&(button->pin), &Pin_Logic_Status);
		switch(button->connection)
		{
			case PULL_DOWN :
			{
				if(GPIO_HIGH == Pin_Logic_Status)
				{
					*state = PRESSED;
				}
				else
				{
					*state = RELEASSED;
				}
				break;
			}
			
			case PULL_UP:
			{
				if(GPIO_HIGH == Pin_Logic_Status)
				{
					*state = RELEASSED;
				}
				else
				{
					*state = PRESSED;
				}
				break;
			}
			
			default: 
			{
				ret = E_NOT_OK;	
				break;
			}
			
			ret = E_OK;
		}
	}
	return ret;
}
