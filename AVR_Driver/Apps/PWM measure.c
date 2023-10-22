/*
 * PWM_measure.c
 *
 * Created: 10/21/2023 9:09:29 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "PWM measure.h"

/*----------------- Global Variables ------------*/

volatile uint8_t flag=0;
volatile uint8_t t1,t2,t3,ton,toff;
volatile uint16_t tt,duty=0;

/*------------------------- Function Definitions -----------------------------*/

void fun()
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		Timer1_InputCaptureEdge(RISING);
		flag=2;
	}
	else if (flag==2)
	{
		t3=ICR1;
		flag=3;
	}
	
}

uint8_t PWM_measure()
{
	sei();
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_SetCallBack(fun);
	Timer1_ICU_InterruptEnable();
	while(1)
	{
		if (flag==3)
		{
			ton=t2-t1;
			toff=t3-t2;
			tt=toff+ton;
			duty=(ton*100)/tt;
			flag=0;
			break;
		}
	}
	return duty;
}