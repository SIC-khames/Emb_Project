#define VALUE_0 0
#define VALUE_1 1
#define VALUE_2 2
#define VALUE_3 3
#define VALUE_4 4
#define VALUE_5 5
#define VALUE_6 6
#define VALUE_7 7


/*
 * DIO_Interface.h
 *
 * Created: VALUE_5/27/2025 10:56:37 AM
 *  Author: Mohamed_khames
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


  /* set diractions*/
  #define INPUT               VALUE_0
  #define OUTPUT              VALUE_1
  /* set Value*/
  #define LOW                 VALUE_0
  #define HIGH                VALUE_1
  
  /* DIO PORTS */
  
  #define  DIO_PORTA          VALUE_0
  #define  DIO_PORTB          VALUE_1
  #define  DIO_PORTC          VALUE_2
  #define  DIO_PORTD          VALUE_3
  
  /*DIO PINS */
  
  #define  DIO_PIN0            VALUE_0
  #define  DIO_PIN1            VALUE_1
  #define  DIO_PIN2            VALUE_2
  #define  DIO_PIN3            VALUE_3
  #define  DIO_PIN4            VALUE_4
  #define  DIO_PIN5            VALUE_5
  #define  DIO_PIN6            VALUE_6
  #define  DIO_PIN7            VALUE_7
  
  /* Pin Prototypes*/
  
  /***************************
  ?  ?Function Name: DIO_void_SetPinDir
  ?  ?Purpose      : set pin dir (OUTPUT , INPUT)
  ?  ?Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_dir
  ?  ?Return value : void
  ***************************/
                              void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8dir);
  /***************************
  ?  ?Function Name: DIO_voidSetPinVal
  ?  ?Purpose      : set pin value (LOW , HIGH)
  ?  ?Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val
  ?  ?Return value : void
  ***************************/														
                              void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin , u8 copy_u8val);
  /***************************
  ?  ?Function Name: DIO_voidTogglePinVal
  ?  ?Purpose      : set pin Toggle (LOW/HIGH)
  ?  ?Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val
  ?  ?Return value : void
  ***************************/						   
                              void DIO_voidTogglePinVal(u8 copy_u8port, u8 copy_u8pin);
  /***************************
  ?  ?Function Name: DIO_u8ReadPinVal
  ?  ?Purpose      : set pin to read Value (LOW/HIGH)
  ?  ?Parameters   : u8 Copy_u8_port,u8 Copy_u8_pin,u8 Copy_u8_val
  ?  ?Return value : void
  ***************************/						   
                              u8 DIO_u8ReadPinVal(u8 copy_u8port, u8 copy_u8pin);
  
  /* Port Prototypes*/
  /***************************
  ?  ?Function Name: DIO_voidSetPortDir
  ?  ?Purpose      : set port direction (input, output)
  ?  ?Parameters   : u8 copy_u8port,u8 copy_u8dir
  ?  ?Return value : void
  ***************************/
                             void DIO_voidSetPortDir(u8 copy_u8port,u8 copy_u8dir);
  /***************************
  ?  ?Function Name: DIO_voidSetPortVal
  ?  ?Purpose      : set port value (input, output)
  ?  ?Parameters   : u8 copy_u8port,u8 copy_u8val
  ?  ?Return value : void
  ***************************/						   
                             void DIO_voidSetPortVal(u8 copy_u8port,u8 copy_u8val);
  

#endif /* DIO_INTERFACE_H_ */














