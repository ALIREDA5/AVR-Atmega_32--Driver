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
//#include "HAL/SevenSegment.h"
#include "HAL/LCD.h"
//#include "MCAL/EXTI.h"


				/*--------------------- Functions Prototypes ---------------------------*/
// this program counts from 99 to 00 through 2 seven-segment
// interrupts counting by 2 leds toggling
void  Led0(void);
void  Led1(void);

/************  special Patterns  *************/

uint8_t StickMan[] = { 0x04,0x0a,0x04,0x0e,0x15,0x04,0xa,0xa};				
uint8_t Bird1[] = { 0x01, 0x03, 0x07, 0x0D, 0x0F, 0x02, 0x05, 0x0A };	
uint8_t Bird2[] = { 0x10, 0x18, 0x1C, 0x16, 0x1E, 0x08, 0x14, 0x0A };	
uint8_t OpenedMouse[] = { 0x0F,0x1E,0x1C,0x18,0x18,0x1C,0x1E,0x0F};
uint8_t ClosedMouse[] = { 0x0E,0x1F,0x1B,0x1F,0x1C,0x1F,0x1F,0x0E};
uint8_t HeartChar[] = { 0x00, 0x00, 0x0a, 0x15, 0x11, 0x0a, 0x04, 0x00};
uint8_t SpeakerChar[] = {0x01, 0x03, 0x07, 0x1f, 0x1f, 0x07, 0x03, 0x01};
uint8_t SmileyFaceChar[] = {0x00, 0x00, 0x0a, 0x00, 0x1f, 0x11, 0x0e, 0x00};
uint8_t BellChar[] = {0x04, 0x0e, 0x0a, 0x0a, 0x0a, 0x1f, 0x00, 0x04};
uint8_t Battery1Char[] = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x1f, 0x1f};
uint8_t Battery2Char[] = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x1f, 0x1f, 0x1f};
uint8_t Battery3Char[] = {0x0e, 0x1b, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};
	
				/*-------------------------- The Main Function ----------------------------*/
int main(void)
{
	
	
    Init_Pins();
    LCD_Init();
	LCD_Create_Character(Battery1Char,1);
	LCD_Create_Character(Battery2Char,2);
	LCD_Create_Character(Battery3Char,3);
	LCD_Create_Character(BellChar,4);
	LCD_Create_Character(OpenedMouse,5);
	LCD_Create_Character(ClosedMouse,6);
	LCD_Create_Character(SpeakerChar,7);
	LCD_Create_Character(StickMan,8);
	LCD_Create_Character(SmileyFaceChar,9);
	LCD_Create_Character(HeartChar,10);
	uint8_t str[]="Ahmed";
	LCD_Clear();
	
    while(1)
    {
		uint8_t l=0;
		while(str[l])
		l++;
		
		for (uint8_t i=l; i>1; i--)
		{
			
			LCD_GOTO(0,0);
			LCD_WriteString(str+i-1);
			_delay_ms(1000);
			LCD_Clear();
		}
		
		for (uint8_t i=0; i<16; i++)
		{
			LCD_GOTO(0,i);
			LCD_WriteString(str);
			_delay_ms(1000);
			LCD_Clear();
		}
	   
    }

// 	enable global interrupt
// 		// sei();
// 		// enable LCD
// 		LCD_Init();
// 		// LCD test
// 		LCD_WriteData('A');
// 					/*------------- External Interrupt INT0 Initialization -------------*/
// 		// enable EXI 0
// 		EXI_Enable(EXI_0);
// 		// rising edge triggering
// 		EXI_TriggerEdge(EXI_0,RISING_EDGE);
// 					/*------------- External Interrupt INT1 Initialization -------------*/
// 		// enable EXI 1
// 		EXI_Enable(EXI_1);
// 		// FALLING EDGE triggering
// 		EXI_TriggerEdge(EXI_1,FALLING_EDGE);
// 		
// 		//  Ex.interrupt --> it calls led fun to toggle led 
// 		EXI_SetCallBack(EXI_0,Led0);
// 		EXI_SetCallBack(EXI_1,Led1);
// 		
	
// 	
// 	
// 	while(1)
// 	{
// 		LCD_WriteData('A');
// 		
// 	}
	
}
					/*--------------------- Interrupt Functions Definitions  ---------------------------*/
void  Led0(void)
{
	for (volatile uint8_t i=0 ; i<200; i++)
	{
		// enable global interrupt to allow another interrupt to cut this interrupt
		sei();
		
		DIO_Toggle(PIND7);
		_delay_ms(100);
	}	
}

void  Led1(void)
{
	for (volatile uint8_t i=0 ; i<100; i++)
	{
		DIO_Toggle(PIND6);
		_delay_ms(100);
	}
}

