/*
 * Calculator_call.h
 *
 * Created: 9/29/2023 1:17:34 AM
 *  Author: Ali Reda
 */ 


#ifndef CALCULATOR_CALL_H_
#define CALCULATOR_CALL_H_

/*----------------- Libraries and Definitions ------------*/

#include "stdint.h"
#include "string.h"
#include "../MCAL/DIO.h"
#include "../HAL/Keypad.h"
#include "../HAL/LCD.h"

/*--------------------- Functions Prototypes ---------------------------*/

void Calculator_call();
int16_t sum(int16_t n1, int16_t n2);
int16_t mul(int16_t n1, int16_t n2);
int16_t sub(int16_t n1, int16_t n2);
float div(float n1, float n2);

#endif /* CALCULATOR_CALL_H_ */