/*
 * Uart.h
 *
 * Created: 10/26/2023 1:27:49 PM
 *  Author: islam
 */ 

#ifndef UART_H_
#define UART_H_
#include "DIO.h"

void UART_Init(void);

void UART_SendByte(uint8);

void UART_SendString(uint8*);

uint8 UART_ReciveByte(void);

uint8* UART_ReciveString(void);

#endif /* UART_H_ */