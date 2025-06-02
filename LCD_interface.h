#define VALUE_0 0
#define VALUE_1 1
#define VALUE_5 5
#define VALUE_6 6

/*
 * LCD_interface.h
 *
 * Created: VALUE_5/27/2025 VALUE_6:25:14 PM
 *  Author: AMIT
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*lcd mode */

#define LCD_4BITMODE        VALUE_1 
#define LCD_8BITMODE        VALUE_0

#define LCD_MODE      LCD_4BITMODE


void LCD_voidSendData( u8 copy_u8data) ; 

void LCD_voidSendCommand( u8 copy_u8command) ; 

void LCD_voidInit(void) ; 

void LCD_voidSendString(char *copy_u8str) ; 


void LCD_voidSendNumber(u32 copy_32num) ; 


void LCD_voidGoToxy(u8 copy_u8x , u8 copy_u8y) ; 


void LCD_voidDrawData(u8 copy_u8pattern , u8 * data ,u8 copy_u8x , u8 copy_u8y ) ; 




#endif /* LCD_INTERFACE_H_ */