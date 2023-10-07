/*
 * Calculator.c
 *
 * Created: 9/29/2023 1:16:24 AM
 *  Author: Ali Reda
 */ 

#include "Calculator_call.h"


void Calculator_call()
{
	Init_Pins();
	LCD_Init();
	int8_t n1=0, n2=0, op=' ';
	float res=0;
	LCD_GOTO(0,0);
	LCD_WriteString("   Calculator ");
	LCD_GOTO(1,0);
	while(1)
	{
		uint8_t x = keypad_Data();
		if (x != DEFAULT_KEY)
		{
			LCD_WriteChar(x);
			
			// to reset the calculator
			if (x == 'c')
			{
				LCD_Clear();
				n1=0;
				n2=0;
				LCD_GOTO(0,0);
				LCD_WriteString("   Calculator ");
				LCD_GOTO(1,0);
			}
			
			// to enter numbers
			if (x>='0' && x<='9')
			{
				n1=n1*10+(x-'0');
			}
			
			// to enter operands
			if (x=='+' || x=='/'|| x=='-' || x=='*')
			{
				op=x;
				n2=n1;
				n1=0;
			}
			// to show result
			if (x=='=' )
			{
				switch (op)
				{
					case '+':
					res=sum(n2,n1);
					break;
					case '-':
					res=sub(n2,n1);
					break;
					case '*':
					res=mul(n2,n1);
					break;
					case '/':
					res=div(n2,n1);
					break;
				}
				LCD_WriteNumber(res);
			}
			
		}
	}
}


int16_t sum(int16_t n1, int16_t n2)
{
	int16_t res = n1 + n2;
	return res;
}

int16_t mul(int16_t n1, int16_t n2)
{
	int16_t res = n1 * n2;
	return res;
}

int16_t sub(int16_t n1, int16_t n2)
{
	int16_t res = n1 - n2;
	return res;
}

float div(float n1, float n2)
{
	float res=0;
	if (n2==0)
	{
		LCD_GOTO(1,0);
		LCD_WriteString("Error");
	}
	else
	{
		res = n1 / n2;
	}
	return res;
}

