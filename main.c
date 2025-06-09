#define VALUE_5 5
#define VALUE_6 6
#include "main.h"
#define F_CPU 16000000UL
#include <util/delay.h>

#define LCD_MAX_COLS 16
#define LCD_MAX_ROWS 2
#define PLAYER_PATTERN_ID 1

int main(void) {
	LCD_voidSendCommand(1); // Clear screen once before drawing the scene
	 u8 Playre[]={0x0E,0x0E,0x1F,0x15,0x0E,0x0E,0x0A,0x0A};// Player
	// Correct LCD Port Direction Setup:
	DIO_voidSetPortDir(LCD_DPORT, 0xFF); // Data port (assuming 8-bit mode)
	DIO_voidSetPortDir(LCD_CPORT, 0x0E); // Control port (RS, RW, E) - Assuming specific pins e.g. 0b00001110 for PC1, PC2, PC3

	LCD_voidInit();

	//set buttons directions to be input
	// Correct Button Pin Direction Setup:
	    DIO_voidSetPinDir(DIO_PORTC, DIO_PIN2, INPUT); // Button on PC2
	    DIO_voidSetPinDir(DIO_PORTC, DIO_PIN7, INPUT); // Button on PC7
	    DIO_voidSetPinDir(DIO_PORTD, DIO_PIN6, INPUT); // Button on PD6

   // Player X,Y Positions
       u8 x=0;
	   u8 y=0;

  // LCD Drawing the Player
       LCD_voidDrawData(1,Playre,x,y);

  while (1){

	//Set buttons forward directions
	  if (DIO_u8ReadPinVal(DIO_PORTC,DIO_PIN2)==0)
	  {
		  while(DIO_u8ReadPinVal(DIO_PORTC,DIO_PIN2)==0);
		  u8 old_x = x;
		  u8 old_y = y;

		  LCD_voidGoToxy(old_x, old_y); // Go to old position
		  LCD_voidSendData(' ');      // Clear player from old position
		  x++;
		  if (x >= LCD_MAX_COLS) {
		      x = LCD_MAX_COLS - 1; // Stop at the edge
		  }
		  LCD_voidGoToxy(x, y);             // Go to new position
		  LCD_voidSendData(PLAYER_PATTERN_ID); // Draw player
		  _delay_ms(50);
	  }
	//Set buttons Backward directions
	  if (DIO_u8ReadPinVal(DIO_PORTC,DIO_PIN7)==0)
	  {
		  while(DIO_u8ReadPinVal(DIO_PORTC,DIO_PIN7)==0);
		  u8 old_x = x;
		  u8 old_y = y;

		  LCD_voidGoToxy(old_x, old_y); // Go to old position
		  LCD_voidSendData(' ');      // Clear player from old position
		  if (x > 0) {
		      x--;
		  }
		  LCD_voidGoToxy(x, y);             // Go to new position
		  LCD_voidSendData(PLAYER_PATTERN_ID); // Draw player
		  _delay_ms(50);
	  }

  //Set buttons to toggle
	 if (DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN6)==0)
	 {
		 while(DIO_u8ReadPinVal(DIO_PORTD,DIO_PIN6)==0);
		 u8 old_x = x;
		 u8 old_y = y;

		 LCD_voidGoToxy(old_x, old_y); // Go to old position
		 LCD_voidSendData(' ');      // Clear player from old position
		 TOGGLE_BIT(y, 0);
		 y &= 0x01; // Mask to keep y as 0 or 1, ensuring it's within LCD_MAX_ROWS
		 LCD_voidGoToxy(x, y);             // Go to new position
		 LCD_voidSendData(PLAYER_PATTERN_ID); // Draw player
		 _delay_ms(50);
	 }

  } // end while
} // end main
