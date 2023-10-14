/*
 * Stop_Watch.h
 *
 * Created: 10/7/2023 2:16:12 PM
 *  Author: Ali Reda
 */ 


#ifndef STOP WATCH_H_
#define STOP WATCH_H_

/*----------------- Libraries and Definitions ------------*/

#include "stdint.h"
#include "string.h"
#include "../MCAL/DIO.h"
#include "../HAL/SevenSegment.h"
#include "../HAL/Keypad.h"
#include "../HAL/LCD.h"
#include "../MCAL/EXTI.h"
#include "../MCAL/Timer0.h"
#include "../MCAL/Timer1.h"
#include "../MCAL/Timer2.h"
/*--------------------- Functions Prototypes ---------------------------*/

void start();
void reset();
void resume();
void stop();
void StopWatch_Call();


#endif /* STOP WATCH_H_ */