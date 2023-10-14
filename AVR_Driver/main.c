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
			/*-------------------------- The Main Function ----------------------------*/
			
int main(void)
{
	sei();
	Init_Pins();
	LCD_Init();
	ADC_Init(ADC_AVCC,ADC_SCALER_64_);
	LCD_GOTO(0,0);
	uint16_t x;
	while(1)
	{
		LCD_GOTO(1,0);
		x=ADC_ReadChannel(ADC0);
		LCD_WriteNumber(x);
		LCD_GOTO(0,0);
	//	x=Temp_sensor(ADC1);
	//	LCD_WriteNumber(x);	
	}
}

