/*
 * UART_services.c
 *
 * Created: 10/22/2023 9:16:12 PM
 *  Author: Ali Reda
 */ 


#include "UART_services.h"



void uart_send_int(uint32_t Num)
{
	uint32_t y=Num;
	uint8_t *x= &y;
	for (uint8_t i=0; i<4; i++)
	{
		uart_send(x[i]);
	}
	
}
uint32_t uart_recieve_int()
{
	uint32_t y=0;
	uint8_t *x= &y;
	for (uint8_t i=0; i<4; i++)
	{
		x[i]= uart_recieve();
	}
	return y;
}

void uart_send_string(uint32_t *str)
{
	for (uint8_t i=0; str[i]; i++)
	{
		uart_send(str[i]);
	}
	uart_send('#');
}

void uart_recieve_string(uint32_t *str)
{
	uint8_t i=0;
	str[i]=uart_recieve();
	while(str[i]!='#')
	{
		i++;
		str[i]=uart_recieve();
	}
	str[i]=0;
}
