/*
 * Fan_Controller.c
 *
 * Created: 10/14/2023 11:30:24 PM
 *  Author: Ali Reda
 */ 

#include "Fan Controller.h"



void Fan_Controller_call()
{
	sei();
	Init_Pins();
	LCD_Init();
	ADC_Init(ADC_AVCC,ADC_SCALER_64_);
	LCD_GOTO(0,0);
	uint16_t x;
	while(1)
	{
		x=Temp_sensor(ADC1);
		LCD_GOTO(0,0);
		LCD_WriteString("Temp : ");
		LCD_WriteNumber(x);
		LCD_GOTO(1,0);
		LCD_WriteString("Speed : ");
		
		if (x<25)
		{
			Mspeed(10,left);
			LCD_WriteNumber(10);
		}
		else if(x>=25 && x<30)
		{
			Mspeed(50,left);
			LCD_WriteNumber(50);
		}
		else if(x>=30 && x<35)
		{
			Mspeed(70,left);
			LCD_WriteNumber(70);
		}
		else if(x>=35 && x<40)
		{
			Mspeed(90,left);
			LCD_WriteNumber(90);
		}
	}
}
