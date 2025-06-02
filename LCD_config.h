#define VALUE_5 5
#define VALUE_6 6

/*
 * LCD_config.h
 *
 * Created: VALUE_5/27/2025 VALUE_6:25:33 PM
 *  Author: AMIT
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_



#if  LCD_MODE  == LCD_8BITMODE
// lcd data port
#define LCD_DPORT    DIO_PORTA

#elif LCD_MODE == LCD_4BITMODE
// LCD 4_ BIT MODE

#define  LCD_DPORT  DIO_PORTA

#define LCD_D4_PIN  DIO_PIN4
#define LCD_D5_PIN  DIO_PIN5
#define LCD_D6_PIN  DIO_PIN6
#define LCD_D7_PIN  DIO_PIN7

#endif 

// LCD control pins 
#define  LCD_CPORT    DIO_PORTB 
 
#define LCD_RS_PIN    DIO_PIN1 
#define LCD_RW_PIN    DIO_PIN3
#define LCD_EN_PIN    DIO_PIN2






#endif /* LCD_CONFIG_H_ */