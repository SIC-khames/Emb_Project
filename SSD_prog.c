#define VALUE_0 0
#define VALUE_1 1
#define VALUE_2 2
#define VALUE_3 3
#define VALUE_4 4
#define VALUE_5 5
#define VALUE_6 6
#define VALUE_7 7

/*
 * SSD_prog.c
 *
 * Created: VALUE_5/25/2025 VALUE_6:20:17 PM
 *  Author: AMIT
 */ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#define F_CPU 16000000UL 
#include <util/delay.h>

void SSD_voidDisplaySingleDigit( u8 copy_u8num, u8 ssd_num) {
	                                    
		/*#if  ssd_num  == SSD1 
		 DIO_voidSetPinDir(SSD_EN_PORT,SSD_EN1_PIN,OUTPUT) ; 
		 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN1_PIN,HIGH) ; 
		#elif ssd_num ==SSD2   
		 DIO_voidSetPinDir(SSD_EN_PORT,SSD_EN2_PIN,OUTPUT) ;
		 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN2_PIN,HIGH) ;						
		#endif 							
	*/
	/*SET SSD PORT DIR */
	DIO_voidSetPortDir(SSD_PORT,0xff) ; 
		switch(copy_u8num){
			
			case VALUE_0 :DIO_voidSetPortVal(SSD_PORT,0X3f) ; break ;
			case VALUE_1 :DIO_voidSetPortVal(SSD_PORT,0x06) ; break ;      
			case VALUE_2 :DIO_voidSetPortVal(SSD_PORT,0x5b) ; break ;
			case VALUE_3 :DIO_voidSetPortVal(SSD_PORT,0x4f) ; break ;
			case VALUE_4 :DIO_voidSetPortVal(SSD_PORT,0x66) ; break ;
			case VALUE_5 :DIO_voidSetPortVal(SSD_PORT,0x6d) ; break ;
			case VALUE_6 :DIO_voidSetPortVal(SSD_PORT,0x7d) ; break ;
			case VALUE_7 :DIO_voidSetPortVal(SSD_PORT,0x07) ; break ;
			case 8 :DIO_voidSetPortVal(SSD_PORT,0x7f) ; break ;
			case 9 :DIO_voidSetPortVal(SSD_PORT,0x6f) ; break ;
}
}


void SSD_voidDisplayTwoDigit( u8 copy_u8num){
	 DIO_voidSetPinDir(SSD_EN_PORT,SSD_EN1_PIN,OUTPUT) ;
	 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN1_PIN,LOW) ;
	 DIO_voidSetPinDir(SSD_EN_PORT,SSD_EN2_PIN,OUTPUT) ;
	 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN2_PIN,LOW) ;
	   u8 num1=VALUE_0 ; 
	   u8 num2=VALUE_0 ; 
	
		num1 = copy_u8num / 10 ;  //  89 
		num2 = copy_u8num %10 ; 
	 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN1_PIN,HIGH) ;
	 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN2_PIN,LOW) ;
	 
	 SSD_voidDisplaySingleDigit(num1,SSD1) ; 
	 _delay_ms(10) ;
	 
		 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN1_PIN,LOW) ;
		 DIO_voidSetPinVal(SSD_EN_PORT,SSD_EN2_PIN,HIGH) ;
		 
		 SSD_voidDisplaySingleDigit(num2,SSD2) ;
		 _delay_ms(10) ;
		
		
		
		
}
