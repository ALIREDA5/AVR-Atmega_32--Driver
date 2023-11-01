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
#include "HAL/Keypad.h"
#include "HAL/LCD.h"
#include "MCAL/EXTI.h"
#include "MCAL/Timer0.h"
#include "MCAL/Timer1.h"
#include "MCAL/ADC.h"
#include "MCAL/UART.h"
#include "Services/UART_services.h"
#include "Sensors/IR Sensor.h"




			/*-------------------------- The Main Function ----------------------------*/
	
int main(void)
{
	Init_Pins();
	LCD_Init();
	uart_init(bits_8,bit_1,Disabled,Asynchronous);
	uint8_t str[]="ali";
	uart_send_Asynch(str);
	while(1)
	{
		for (uint8_t i=0; i<9; i++)
		{
			LCD_GOTO(0,0);
			LCD_WriteChar(i);
		}
		
		
	}
}

