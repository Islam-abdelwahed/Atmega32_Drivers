#include "Ext_Int_Cfg.h"
#include "Atmega32_Registers.h"

#ifndef EXT_INT_H_
#define EXT_INT_H_

#define GLOBAL_INTERRUPT_ENABLE					1
#define GLOBAL_INTERRUPT_DISABLE				0

#define GLOBAL_INTERRUPT						7
#define EXTERNAL_INTERRUPT0						6
#define EXTERNAL_INTERRUPT1						7
#define EXTERNAL_INTERRUPT2						5

#define INTERRUPT_TRIGGER_LOW_LEVEL				0
#define INTERRUPT_TRIGGER_RISING_EDGE			1
#define INTERRUPT_TRIGGER_FALLING_EDGE			2
#define INTERRUPT_TRIGGER_ANY_LOGICAL_CHANGE	3


void setGlobalInterrupt(void);	

void externalInterrupt0_Init(void);

void externalInterrupt1_Init(void);

void externalInterrupt2_Init(void);



#endif /* EXT_INT_H_ */