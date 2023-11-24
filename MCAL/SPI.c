#include "SPI.h"


void SPI_MasterInit(void){
	DIO_setPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
	
	SPI->SPCR.SPR0=true;
	SPI->SPCR.SPR1=true;
	SPI->SPCR.MSTR=true;
	SPI->SPCR.SPE=true;
 }

void SPI_SlaveInit(void){
	DIO_setPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDir(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT);
	
	SPI->SPCR.SPE=true;
 }

void SPI_InitTrans(void){
	DIO_setPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW);
 }

void SPI_TermTrans(void){
		DIO_setPinDir(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH);
	}
	

uint8 SPI_Transive(uint8 data){
	uint8 rec_data=0;
	
	SPI->SPDR=data;
	
	while(!GET_BIT(SPI->SPSR,7));
	
	rec_data=SPI->SPDR;
	
	return rec_data;
	}
	