#include "Uart.h"

void UART_Init(void){
 uint32 BR_Value=0;
 
 DIO_setPinDir(DIO_PORTD,DIO_PIN0, DIO_PIN_INPUT);
 DIO_setPinDir(DIO_PORTD,DIO_PIN1, DIO_PIN_OUTPUT);
 
 UCSRB |= 0x18;
 UCSRC |= 0x86;
 
 BR_Value = ((160000)/(16*96))-1;
 
 UBRRL =BR_Value;
 
 }

void UART_SendByte(uint8 data){
	UDR =data;
	
	while(GET_BIT(UCSRA,5)==0);
 }

void UART_SendString(uint8* str){
 uint8 i=0;
 while(str[i] != '\0'){
	 UART_SendByte(str[i]);
	 i++;
 }
 }

uint8 UART_ReciveByte(void){
	uint8 data=0;
	while(GET_BIT(UCSRA,7)==0);
	
	data=UDR;
	
	return data;
}

uint8* UART_ReciveString(void){
	  uint8 receivedChar,i=0;
	  static uint8* str;
	  
	  do {
		  receivedChar = UART_ReciveByte();
		  str[i] = receivedChar;
		  i++;
	  } while (receivedChar != '\0');
}
