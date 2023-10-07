/*
* Timer_0_test.c
*
* Created: 10/7/2023 12:04:56 AM
*  Author: Ali Reda
*/ 

/*----------------- Libraries and Definitions ------------*/


// #include "stdint.h"
// #include "string.h"
// #include "MCAL/DIO.h"
// #include "HAL/SevenSegment.h"
// #include "HAL/Keypad.h"
// #include "HAL/LCD.h"
// #include "MCAL/EXTI.h"
// #include "Apps/Calculator_call.h"
// #include "MCAL/Timer0.h"
// #include "MCAL/Timer1.h"
// #include "MCAL/Timer2.h"
// #include "MCAL/WD_Timer.h"

// /*--------------------------- Global Variables ------------------------------*/
// volatile uint16_t y=0;
// 
// void test()
// {
// 	y++;
// }
// /*-------------------------- The Main Function ----------------------------*/
// int main(void)
// {
// 	sei();
// 	Init_Pins();
// 	LCD_Init();
// 	TIMER0_Init(CTC,TIMER0_SCALER_8,Disconnected);
// 	TIMER0_Init(NORMAL_MODE,TIMER0_SCALER_8,Disconnected); // first init timer
// 	TIMER0_OVF_SetCallBack(test);  // you have to pass function to CallBack fun before enabling OC Interrupt
// 	TIMER0_OVFInterrupt_Enable();  // enable interrupt
// 	TCNT0=6;
// 	while(1)
// 	{
// 	TIMER1_SetInterrupt_ms(1,test);
// 	LCD_GOTO(0,1);
// 	LCD_WriteNumber(y);
// 	}
// 				
// }
// 
