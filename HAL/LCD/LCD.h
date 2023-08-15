
#ifndef LCD_H_
#define LCD_H_
#include "STD.h"
#include "LCD_CFG.h"
#include "DIO.h"
#define F_CPU 12000000
#include <util/delay.h>


void LCD_INIT(void);
void LCD_WRITE_CMD(uint8 cmd);
void LCD_WRITE_DATA(uint8 value);
void LCD_GOTO(uint8 row,uint8 col);
void LCD_WRITE_STRING(uint8* str);
void LCD_CLR(void);
void LCD_WIRTE_INTEGER(sint32 number);

#endif /* LCD_H_ */