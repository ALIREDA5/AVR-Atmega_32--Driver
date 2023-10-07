/*
 * GccApplication1.c
 *
 * Created: 9/18/2023 6:55:29 PM
 * Author : Ali Reda
 */ 


				/*----------------- Libraries and Definitions ------------*/


#include "stdint.h"
#include "string.h"
#include "MCAL/DIO.h"
#include "HAL/SevenSegment.h"
#include "HAL/Keypad.h"
#include "HAL/LCD.h"
#include "MCAL/EXTI.h"
#include "Apps/Calculator_call.h"
#include "Apps/Stop Watch.h"
#include "MCAL/Timer0.h"
#include "MCAL/Timer1.h"
#include "MCAL/Timer2.h"
#include "MCAL/WD_Timer.h"

		
			/*-------------------------- The Main Function ----------------------------*/
			
int main(void)
{
	StopWatch_Call();
}

