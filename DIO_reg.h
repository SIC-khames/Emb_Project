#define VALUE_5 5
#define VALUE_6 6

/*
 * DIO_reg.h
 *
 * Created: VALUE_5/22/2025 VALUE_6:11:50 PM
 *  Author: AMIT
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_


/* Group  A */

#define  PORTA_REG       *((volatile u8*)0x3B)
#define  DDRA_REG        *((volatile u8*)0x3A)
#define  PINA_REG        *((volatile u8*)0x39)

/*Group B*/
#define  PORTB_REG       *((volatile u8*)0x38)
#define  DDRB_REG        *((volatile u8*)0x37)
#define  PINB_REG        *((volatile u8*)0x36)

/*Group C*/
#define  PORTC_REG       *((volatile u8*)0x35)
#define  DDRC_REG        *((volatile u8*)0x34)
#define  PINC_REG        *((volatile u8*)0x33)

/*Group D*/
#define  PORTD_REG       *((volatile u8*)0x32)
#define  DDRD_REG        *((volatile u8*)0x31)
#define  PIND_REG        *((volatile u8*)0x30)



#endif /* DIO_REG_H_ */