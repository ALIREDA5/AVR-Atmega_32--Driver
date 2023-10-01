/*
 * Timer.c
 *
 * Created: 9/21/2023 9:07:03 PM
 *  Author: Ali Reda
 */ 

/*----------------- Libraries and Definitions ------------*/

#include "Timer.h"


static void (*Timer0_OVF_Fptr) (void)=NULLptr;
static void (*Timer0_OC0_Fptr) (void)=NULLptr;

static void (*Timer2_OVF_Fptr) (void)=NULLptr;
static void (*Timer2_OC2_Fptr) (void)=NULLptr;

static void (*Timer1_OVF_Fptr) (void)=NULLptr;
static void (*Timer1_OCA_Fptr) (void)=NULLptr;
static void (*Timer1_OCB_Fptr) (void)=NULLptr;
static void (*Timer1_ICU_Fptr) (void)=NULLptr;


			/****************************** Timer 2 *************************************/

/*------------------------- Function Definition Of setting TCNT register  -----------------------------*/

void TIMER2_SET(uint8_t time){
	TCNT2=time;
}

/*------------------------- Function Definition Of setting OCR2 register -----------------------------*/

void TIMER2_OC(uint8_t time){
	OCR2=time;
}

/*------------------------- Function Definition Of initializing the timer 2  -----------------------------*/

void TIMER2_Init(Operation_Mode mode,Timer2_Scaler scalar,OC2_Mode OC )
{
	switch (mode){
		case NORMAL_MODE:
		CLEAR_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		break;
		case PWM:
		SET_BIT(TCCR2,WGM20);
		CLEAR_BIT(TCCR2,WGM21);
		break;
		case CTC:
		CLEAR_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		case FAST_PWM:
		SET_BIT(TCCR2,WGM20);
		SET_BIT(TCCR2,WGM21);
		break;
		
	}
	switch(scalar){
		case TIMER2_STOP:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break; 
		case TIMER2_SCALER_1:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_8:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_32:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		CLEAR_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_64:
		CLEAR_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_128:
		SET_BIT(TCCR2,CS20);
		CLEAR_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_256:
		CLEAR_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;
		case TIMER2_SCALER_1024:
		SET_BIT(TCCR2,CS20);
		SET_BIT(TCCR2,CS21);
		SET_BIT(TCCR2,CS22);
		break;

	}
	switch (OC){
		case Disconnected:
		CLEAR_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);
		break;
		case Toggle:
		SET_BIT(TCCR2,COM20);
		CLEAR_BIT(TCCR2,COM21);
		break;
		case NonInverting:
		CLEAR_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
		case Inverting:
		SET_BIT(TCCR2,COM20);
		SET_BIT(TCCR2,COM21);
		break;
	}
	
}

		/****************************Timer 2 Interrupt functions*********************************/

/*------------------------- Function Definition Of  TIMER2_Over Flow Interrupt_Enable  -----------------------------*/

void TIMER2_OVFInterrupt_Enable(void){
	SET_BIT(TIMSK,TOIE2);
}

/*------------------------- Function Definition Of TIMER2_Over Flow Interrupt_disable  -----------------------------*/

void TIMER2_OVFInterrupt_Disable(void){
	CLEAR_BIT(TIMSK,TOIE2);

}

/*------------------------- Function Definition Of TIMER2_output compare Interrupt_disable -----------------------------*/

void TIMER2_OCInterrupt_Enable(void){
	SET_BIT(TIMSK,OCIE2);

}

/*------------------------- Function Definition Of TIMER2_output compare Interrupt_disable -----------------------------*/

void TIMER2_OCInterrupt_Disable(void){
	CLEAR_BIT(TIMSK,OCIE2);

}

/*------------------------- TIMER2_SetCallBack Function Definition -----------------------------*/

void TIMER2_SetCallBack(void (*ptr)(void)){
	Timer2_OC2_Fptr=ptr;
}

/********************************* Timer 2 ISR functions ******************************/

ISR(TIMER2_COMP_vect){
	Timer2_OC2_Fptr();
}


/****************************** Timer 1 *************************************/

void Timer1_Init(Timer1_Mode mode1, Timer1_Scaler scaler, Timer1_OC1A_Mode oc1a_mode, Timer1_OC1B_Mode oc1b_mode)
{
	switch (mode1)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
	}
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);

}

/****************************Timer 1 Interrupt functions**************************************/

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}

/*********************************Timer 1 Call Back functions*****************************************/

void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr=LocalFptr;
}


/*********************************Timer 1 ISR functions*********************************************/
ISR(TIMER1_OVF_vect)
{
	if(Timer1_OVF_Fptr!=NULLptr)
	{
		Timer1_OVF_Fptr();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(Timer1_OCA_Fptr!=NULLptr)
	{
		Timer1_OCA_Fptr();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(Timer1_OCB_Fptr!=NULLptr)
	{
		Timer1_OCB_Fptr();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(Timer1_ICU_Fptr!=NULLptr)
	{
		Timer1_ICU_Fptr();
	}
}