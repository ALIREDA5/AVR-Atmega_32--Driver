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




			/*-------------------------- The Main Function ----------------------------*/
			
int main(void)
{
	Init_Pins();
	LCD_Init();
	LCD_GOTO(0,0);
	LCD_WriteString("UART Test");
	uart_init(bits_8,bit_1,Disabled,Asynchronous);
	uart_send('f');
	uint8_t x;
	while(1)
	{
		x=uart_recieve();
		LCD_GOTO(1,1);
		LCD_WriteChar(x);
	
	}
}

