/*
 * ADC.h
 *
 * Created: 8/17/2023 1:31:01 PM
 *  Author: Islam
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "STD.h"
#include "Atmega32_Registers.h"
#include "BIT_MATH.h"

#define ADC_VREF_AREF		0
#define ADC_VREF_AVCC		1
#define ADC_VREF_RESERVED	2
#define ADC_VREF_INTERNAL	3


#define ADC_CHANNEL_1		1
#define ADC_CHANNEL_2		2
#define ADC_CHANNEL_3		3
#define ADC_CHANNEL_4		4
#define ADC_CHANNEL_5		5
#define ADC_CHANNEL_6		6
#define ADC_CHANNEL_7		7

#define ADC_AUTO_TRIGGER	0
#define ADC_MANUAL			1

#define ADC_PRESC_2			0
#define ADC_PRESC_4			1
#define ADC_PRESC_8			2
#define ADC_PRESC_16		3
#define ADC_PRESC_32		4
#define ADC_PRESC_64		5
#define ADC_PRESC_128		6

#define ADC_RIGHT_ADJUST	0
#define ADC_LEFT_ADJUST		1

#define ADC_INTERRUPT_ENABLE	0
#define ADC_INTERRUPT_DISABLE	1


void ADC_INIT(void);
void ADC_READ(uint16* value);
void ADC_SELECT_CHANNEL(uint8 Channel);


#endif /* ADC_H_ */