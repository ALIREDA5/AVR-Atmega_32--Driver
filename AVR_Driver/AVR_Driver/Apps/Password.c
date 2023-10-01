/*
 * Password.c
 *
 * Created: 9/29/2023 5:29:39 PM
 *  Author: Ali Reda
 */

/*************************** Project Brief ****************************/

/* this is AVR-password detection application to check if password is right or wrong 
and if it is wrong you have two more trials before showing thief on LCD and giving an alarm */

/*----------------- Libraries and Definitions ------------*/


#include "stdint.h"
#include "string.h"
#include "MCAL/DIO.h"
#include "HAL/SevenSegment.h"
#include "HAL/Keypad.h"
#include "HAL/LCD.h"
#include "MCAL/EXTI.h"
#include "Apps/Calculator_call.h"

/*-------------------------- The Main Function ----------------------------*/
/*
int main(void)
{
	Init_Pins();
	LCD_Init();
	char PW = "1234";	// password to compare with
	char PW_arr[5]={0};
	uint8_t i=0, flag=0;
	LCD_Clear();
	LCD_GOTO(0,0);
	LCD_WriteString("Enter Password");
	uint8_t j=0;
	while(1)
	{
		uint8_t x= keypad_Data();
		
		if (x!=DEFAULT_KEY)
		{
			if (x=='c')
			{
				PW_arr[5]= 0;
				i=0, flag=0;
				LCD_Clear();
				LCD_GOTO(0,0);
				LCD_WriteString("Enter Password");
			}
			if (x>='0' && x<='9')
			{
				PW_arr[i]=x;
				LCD_GOTO(1,i);
				LCD_WriteChar('*');
				i++;
				if (i==4)
				{
					flag=1;
				}
			}
			
		}
		if (flag==1)
		{
			if (!strcmp(PW,PW_arr))
			{
				LCD_Clear();
				LCD_GOTO(0,0);
				LCD_WriteString("Correct Password");
				flag=0;
				
			}
			else
			{
				LCD_Clear();
				LCD_GOTO(0,0);
				LCD_WriteString("wrong Password");
				flag=0;
				if (j<2)
				{
					j++;
				}
				else
				{
					LCD_Clear();
					LCD_WriteString("Thief");
					DIO_Writepin(PIND0,HIGH);
					_delay_ms(2000);
					DIO_Writepin(PIND0,LOW);
				}
				
			}
			
		}
	}
	
}
*/