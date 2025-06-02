#define VALUE_0 0
#define VALUE_1 1
#define VALUE_2 2
#define VALUE_4 4
#define VALUE_5 5
#define VALUE_6 6
#define VALUE_7 7

/*
 * LCD_prog.c
 *
 * Created: VALUE_5/27/2025 VALUE_6:25:46 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define  F_CPU 16000000UL 
#include <util/delay.h>
#include "LCD_interface.h"
#include "LCD_config.h"



static void LCD_voidSHD(u8 copy_u8data){  //  1101  0011  // DATA>>VALUE_4 
	
	u8 loc_arr[VALUE_4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ; 
	
	u8 loc_in=VALUE_0 ; 
	
	for (loc_in=VALUE_0 ; loc_in< VALUE_4 ;loc_in++)
	{
		DIO_voidSetPinVal(LCD_DPORT,loc_arr[loc_in],GET_BIT(copy_u8data,loc_in)) ; 
		
		
	}
			
}


static void LCD_voidSendEnablePulse(){
		DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
		_delay_ms(VALUE_2) ;
		DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
		
}

void LCD_voidSendData(u8 copy_u8data) {
	
	
	/*set rs pin to low ---> send DATA  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH) ;
	/* set RW PIN to low --->  write data  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ;
	
	#if LCD_MODE == LCD_8BITMODE
	/*SEND data */
	
	DIO_voidSetPortVal(LCD_DPORT,copy_u8data) ;
      // enable pin 
	  LCD_voidSendEnablePulse() ; 
	#elif LCD_MODE ==LCD_4BITMODE 
	LCD_voidSHD(copy_u8data>>VALUE_4) ; 
	  LCD_voidSendEnablePulse() ;
	  LCD_voidSHD(copy_u8data) ; 
	  LCD_voidSendEnablePulse() ;
	  #endif 
	
}

void LCD_voidSendCommand(u8 copy_u8command){
	
	/*CLR rs pin to low ---> send command  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW) ; 
	/* LCR RW PIN to low --->  write data  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ; 
	
	#if LCD_MODE == LCD_8BITMODE
	/*SEND data */
	
	DIO_voidSetPortVal(LCD_DPORT,copy_u8command) ;
	// enable pin
	LCD_voidSendEnablePulse() ;
	#elif LCD_MODE ==LCD_4BITMODE
	LCD_voidSHD(copy_u8command>>VALUE_4) ;
	LCD_voidSendEnablePulse() ;
	LCD_voidSHD(copy_u8command) ;
	LCD_voidSendEnablePulse() ;
	#endif
	
}

void LCD_voidInit(void){
	
	_delay_ms(40) ; 
	
	#if LCD_MODE == LCD_8BITMODE 
	/*send command ( Function set ) */
	LCD_voidSendCommand(0x38) ; 
	#elif LCD_MODE ==LCD_4BITMODE 
	
	LCD_voidSHD(0b0010) ; 
	LCD_voidSendEnablePulse() ; 
	LCD_voidSHD(0b0010) ;
	LCD_voidSendEnablePulse() ;
    LCD_voidSHD(0b1000) ;
    LCD_voidSendEnablePulse() ;
	#endif 
   /*send command  (display on /off control) */	 
	 LCD_voidSendCommand(0x0C) ; 
	 
   /*send command  (LCD CLR ) */
   LCD_voidSendCommand(0x01) ; 
	
}


void LCD_voidSendString(char  *copy_u8str){
	
	 u8 i=VALUE_0 ; 
	
	 while(copy_u8str[i] != '\VALUE_0'){
		 
		 LCD_voidSendData(copy_u8str[i]) ; 
		 i++ ; 
		 
	 }

}


void LCD_voidGoToxy(u8 copy_u8x , u8 copy_u8y){
	
	u8 loc_u8ddramAddress=VALUE_0 ; 
	
	
	if (copy_u8y ==VALUE_0)
	{
		loc_u8ddramAddress = copy_u8x ; 
	}
	else if (copy_u8y==VALUE_1)
	{
		loc_u8ddramAddress = copy_u8x+0x40 ; 
	}
	else {
	                   //  loc_u8address = x + 0x40 * y  ; 	
		
	}
	
	
	// set DDRAM 
	
	SET_BIT(loc_u8ddramAddress,VALUE_7) ; 
	// send command 
	LCD_voidSendCommand(loc_u8ddramAddress) ; 
	
	
	
	
	
	
}



void LCD_voidDrawData(u8 copy_u8pattern , u8 * data ,u8 copy_u8x , u8 copy_u8y ){
	
	u8 Loc_u8CGRAM_Address=VALUE_0 ; 
	
	u8 loc_in=VALUE_0 ; 
	// cal address
	
   Loc_u8CGRAM_Address = copy_u8pattern * 8 ; 
   
   // set CGRAM 
   
   CLR_BIT(Loc_u8CGRAM_Address,VALUE_7) ; 
   SET_BIT(Loc_u8CGRAM_Address,VALUE_6) ; 
   
   LCD_voidSendCommand(Loc_u8CGRAM_Address) ; 
   
   
   // draw data 
   
    for (loc_in=VALUE_0 ; loc_in < 8 ; loc_in++)
    {
		
		LCD_voidSendData(data[loc_in]) ; 
		
    }
   
   
   // set DDRAM 
   
   LCD_voidGoToxy(copy_u8x,copy_u8y) ; 
   
   
   LCD_voidSendData(copy_u8pattern) ; 
	
}
