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
#include "Utils.h"
#include "HAL/SevenSegment.h"
#include "HAL/Keypad.h"
#include "HAL/LCD.h"
#include "MCAL/EXTI.h"
#include "MCAL/Timer0.h"
#include "MCAL/Timer1.h"
#include "HAL/Servo.h"
#include "MCAL/ADC.h"
#include "Sensors/LM35.h"
#include "Apps/Fan Controller.h"		
			/*-------------------------- The Main Function ----------------------------*/
			
int main(void)
{
	Fan_Controller_call();

}

