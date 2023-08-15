
#include "LCD.h"



void LCD_INIT(void){
	#if LCD_MODE == 4
	
	DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	//DIO_setPinDir(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);

	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D4,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D5,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D6,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_4BIT_DATA_PORT,LCD_D7,DIO_PIN_OUTPUT);

	_delay_ms(100);
	
	//LCD_WRITE_CMD(0x33);
	//LCD_WRITE_CMD(0x32);
	//LCD_WRITE_CMD(0x28);
	
	LCD_WRITE_CMD(0x01);
	//LCD_WRITE_CMD(0x02);
	LCD_WRITE_CMD(0x0E);
		LCD_WRITE_CMD(0x18);



	_delay_ms(5);

	#elif LCD_MODE==8
	DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
	//DIO_setPinDir(LCD_8BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPortDir(LCD_8BIT_CMD_PORT,DIO_PORT_OUTPUT);
	
	_delay_ms(100);

	#endif

};


void LCD_WRITE_CMD(uint8 cmd){
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	PORTB=(cmd & 0x0F) ;
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	PORTB=(cmd >> 4) ;

	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);
	
};


void LCD_WRITE_DATA(uint8 value){
	
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	PORTB=(value & 0x0F) | (PORTB & 0xF0) ;

	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);

	PORTB=(value >> 4) | (PORTB & 0xF0);

	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_4BIT_CMD_PORT,LCD_E_PIN,DIO_PIN_LOW);
	
	_delay_ms(5);

};
void LCD_GOTO(uint8 row,uint8 col){

	uint8 pos[4]={0x80,0xC0,0x94,0xD4};
	LCD_WRITE_CMD(pos[row]+col);

};
void LCD_WRITE_STRING(uint8* str){

	int i=0;
	while( str[i] != '\0' ){
		LCD_WRITE_DATA( str[i] );
		i++;
	}
	
};

void LCD_WIRTE_INTEGER(sint32 number){

sint32 y=1;

if(number<0){
LCD_WRITE_DATA('-');
number*=-1;
}

while(number>0)
{
	y=((y*10)+(number%10));
	number/=10;
}

while(y>1)
{
	LCD_WRITE_DATA(((y%10)+48));
	y/=10;
}

}

void LCD_CLR(void){
	LCD_WRITE_CMD(0x01);
};

