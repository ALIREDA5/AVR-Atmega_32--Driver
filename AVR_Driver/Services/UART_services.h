/*
 * UART_services.h
 *
 * Created: 10/22/2023 9:16:29 PM
 *  Author: Ali Reda
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "../MCAL/UART.h"

void uart_send_int(uint32_t Num);
uint32_t uart_recieve_int();
void uart_send_string(uint32_t *str);
void uart_recieve_string(uint32_t *str);

#endif /* UART_SERVICES_H_ */