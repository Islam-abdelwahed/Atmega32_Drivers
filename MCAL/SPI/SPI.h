
#ifndef SPI_H_
#define SPI_H_
#include "STD.h"
#include "Atmega32_Registers.h"
#include "DIO.h"
void SPI_MasterInit(void);

void SPI_SlaveInit(void);

void SPI_InitTrans(void);

void SPI_TermTrans(void);

uint8 SPI_Transive(uint8 data);

#endif /* SPI_H_ */