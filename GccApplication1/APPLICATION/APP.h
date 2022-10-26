/*
 * APP.h
 *
 * Created: 10/1/2022 6:39:42 AM
 * Author : Mohamed Nagy
 */ 




#ifndef APP_H_
#define APP_H_


#include "../MCAL/DIO/DIO.h"
#include "../ECU/LED/LED.h"
#include "../ECU/BUTTON/BUTTON.h"
#include "../MCAL/TIMER0//TIMER_0.h"
#include "../MCAL/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"

#define redCarState						0
#define yellowCarState					1
#define greanCarState					2



void appStart();
void ifPressed();
void normalMode();
void pedstrainsMode();
void turnOffLeds();
void carGreenLedOn();
void carRedLedOn();

#endif /* APP_H_ */