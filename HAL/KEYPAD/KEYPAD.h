
#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "KEPPAD_CFG.h"
#define F_CPU 12000000
#include <util/delay.h>
#include "STD.h"
#include "DIO.h"

#define COL_INIT 0
#define COL_FINAL 3

#define ROW_INIT 0
#define ROW_FINAL 3


void KEYPAD_INIT(void);
uint8 keypadGetValue(void);


#endif /* KEY_PAD_H_ */