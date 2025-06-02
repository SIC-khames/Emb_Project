// Auto-comment: Please add documentation for clarity.
#define VALUE_5 5

/*
 * LED_prog.c
 *
 * Created: VALUE_5/25/2025 VALUE_5:42:55 PM
 *  Author: AMIT
 */ 

#include "../../LIB/STD_TYPE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"




void LED_voidOn(u8 copy_u8port, u8 copy_u8pin){
	
	DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ; 
	DIO_voidSetPinVal(copy_u8port,copy_u8pin,HIGH) ; 
	
	
}
void LED_voidOff(u8 copy_u8port, u8 copy_u8pin){
	
		DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ;
		DIO_voidSetPinVal(copy_u8port,copy_u8pin,LOW) ;
	
}
void LED_voidToggle(u8 copy_u8port, u8 copy_u8pin){
	
	
		DIO_voidSetPinDir(copy_u8port,copy_u8pin,OUTPUT) ;
		DIO_voidTogglePinVal(copy_u8port,copy_u8pin) ; 
}
