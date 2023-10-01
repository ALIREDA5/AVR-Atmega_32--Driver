/*
 * Timer.h
 *
 * Created: 9/21/2023 9:07:17 PM
 *  Author: Ali Reda
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*----------------- Libraries and Definitions ------------*/

#include "../MemoryMap.h"
#include "../Utils.h"

#define  NULLptr  ((void*)0)

/*********************************Timer0************************************/
typedef enum{
	NORMAL_MODE,
	PWM,
	CTC,
	FAST_PWM
	}Operation_Mode;
	
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
	}Timer0_Scaler;
	
typedef enum{
	Disconnected,
	Toggle,
	Inverting,
	NonInverting
	}OC0_Mode;

/*--------------------- Timer 0 Functions Prototypes ---------------------------*/

void TIMER0_Init(Operation_Mode mode,Timer0_Scaler scalar,OC0_Mode Toggle);
void TIMER0_SET(uint8_t time);
void TIMER0_OC(uint8_t time);
void TIMER0_OVFInterrupt_Enable(void);
void TIMER0_OVFInterrupt_Disable(void);
void TIMER0_OCInterrupt_Enable(void);
void TIMER0_OCInterrupt_Disable(void);
void TIMER0_SetCallBack(void (*ptr)(void));

/*********************************Timer2************************************/

typedef enum{
	NORMAL_MODE,
	PWM,
	CTC,
	FAST_PWM
}Operation_Mode;

typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_32,
	TIMER2_SCALER_64,
	TIMER2_SCALER_128,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024
}Timer2_Scaler;

typedef enum{
	Disconnected,
	Toggle,
	Inverting,
	NonInverting
}OC2_Mode;

/*--------------------- Timer 2 Functions Prototypes ---------------------------*/

void TIMER2_Init(Operation_Mode mode,Timer2_Scaler scalar,OC2_Mode Toggle);
void TIMER2_SET(uint8_t time);
void TIMER2_OC(uint8_t time);
void TIMER2_OVFInterrupt_Enable(void);
void TIMER2_OVFInterrupt_Disable(void);
void TIMER2_OCInterrupt_Enable(void);
void TIMER2_OCInterrupt_Disable(void);
void TIMER2_SetCallBack(void (*ptr)(void));


/********************************* Timer1 ************************************/

typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL1_FALLING,
	EXTERNAL1_RISING
}Timer1_Scaler;

typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE
}Timer1_Mode;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING
}Timer1_OC1A_Mode;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING
}Timer1_OC1B_Mode;

typedef enum
{
	RISING,
	FALLING
}ICU_Edge_type;

/*--------------------- Timer 1 Functions Prototypes ---------------------------*/

void Timer1_Init( Timer1_Mode mode1,Timer1_Scaler scaler,Timer1_OC1A_Mode oc1a_mode,Timer1_OC1B_Mode oc1b_mode);
void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void));
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void));
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void));

#endif 