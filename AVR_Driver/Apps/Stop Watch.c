/*
* Stop_Watch.c
*
* Created: 10/7/2023 2:15:54 PM
*  Author: Ali Reda
*/ 

/*----------------- Libraries and Definitions ------------*/

#include "Stop Watch.h"

/*--------------------------- Global Variables ------------------------------*/
	
volatile uint8_t sec=10;
volatile uint8_t min=0;
volatile uint8_t hour=0;

/*-------------------------- Function to start counting  ----------------------------*/
void start()
{
	if (hour==0 && min==0 && sec==0)
	{
		DIO_Writepin(PIND0,HIGH); // alarm on
	}
	else
	{
		sec--;
	}
	if (min!=0 && sec==0)
	{
		sec=60;
		min--;
	}
	if (hour!=0 && min==0 && sec==0)
	{
		min=60;
		hour--;
	}
}
/*-------------------------- Function to reset counting start ----------------------------*/
void reset()
{
	uint8_t n1=0;
	uint8_t count=0;
	while(1)
	{
		uint8_t x = keypad_Data();
		if (x != DEFAULT_KEY)
		{
			if (x>='0' && x<='9')
			{
				n1=n1*10+(x-'0');
				count++;
			}
			if (count==2)
			{
				hour=n1;
				n1=0;
			}
			if (count==4)
			{
				min=n1;
				n1=0;
			}
			if (count==6)
			{
				sec=n1;
				n1=0;
				break;
			}
		}
	}
}
/*-------------------------- Function to resume counting ----------------------------*/
void resume()
{
	// start clock
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}
/*-------------------------- Function to stop counting ----------------------------*/
void stop()
{
	// close clock
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
}

void StopWatch_Call()
{
	sei();
	Init_Pins();
	LCD_Init();
	TIMER0_Init(CTC,TIMER0_SCALER_8,Disconnected);
	EXI_Enable(EXI_0);
	EXI_TriggerEdge(EXI_0,RISING_EDGE);
	EXI_SetCallBack(EXI_0,stop);
	EXI_Enable(EXI_1);
	EXI_TriggerEdge(EXI_1,RISING_EDGE);
	EXI_SetCallBack(EXI_1,resume);
	EXI_Enable(EXI_2);
	EXI_TriggerEdge(EXI_2,RISING_EDGE);
	EXI_SetCallBack(EXI_2,reset);
	LCD_GOTO(0,3);
	LCD_WriteString("STOP WATCH");
	
	while(1)
	{
		TIMER0_SetInterrupt_ms(1,start);
		LCD_GOTO(1,4);
		LCD_WriteNumber2D(hour);
		LCD_WriteChar(':');
		LCD_WriteNumber2D(min);
		LCD_WriteChar(':');
		LCD_WriteNumber2D(sec);
	}
}