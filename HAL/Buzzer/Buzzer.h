
#ifndef LED_H_
#define LED_H_

#include "DIO.h"

#define BUZZER_ON   1
#define BUZZER_OFF  0
#define BUZZER_PORT DIO_PORTC
#define BUZZER_PIN  DIO_PIN6

void BUZZER_Init();
void BUZZER_Status(uint8 Buz_sta);
void BUZZER_Toggle();


#endif 