/*
 * LED.h
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */



#ifndef LED_H
#define	LED_H

/************************************************************************/
/*                        section : includes                            */
/************************************************************************/
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER0/TIMER_0.h"

/************************************************************************/
/*                   section: data type declaration                     */
/************************************************************************/

typedef enum
{
    LED_OFF = 0,
    LED_ON        
}EN_ledStatus_t;

typedef struct
{
    uint8 port;
    uint8 pin;
    EN_ledStatus_t status;
}ST_led_t;


/************************************************************************/
/*                      section:function declaration                    */
/************************************************************************/

Std_ReturnType Led_Init(const ST_led_t* led);
Std_ReturnType Led_Turn_On(const ST_led_t* led);
Std_ReturnType Led_Turn_Off(const ST_led_t* led);
Std_ReturnType Led_Toggle(const ST_led_t* led);
EN_ledStatus_t Led_State(const ST_led_t* led);
Std_ReturnType Led_Blink_aSecond(const ST_led_t* led);
Std_ReturnType Two_Led_Blink_aSecond(const ST_led_t* led_1, const ST_led_t* led_2);



#endif	/* LED_H */

