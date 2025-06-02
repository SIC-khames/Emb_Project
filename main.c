// Auto-comment: Please add documentation for clarity.
#define VALUE_5 5
#define VALUE_6 6

/*

EM556.c
Created: VALUE_5/22/2025 VALUE_6:05:18 PM
Author : AMIT */
#include "main.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

int main(void) {
	u8 Ball[] = {0x00, 0x00, 0x0E, 0x1F, 0x1F, 0x1F, 0x0E, 0x00};
	u8 GoalKeeper[] = {0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	u8 Player1[] = {0x06, 0x0A, 0x12, 0x02, 0x02, 0x02, 0x1F, 0x00};
	u8 Player2[] = {0x1F, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F, 0x1F};

	DIO_voidSetPortDir(LCD_CPORT, 0x0E);
	DIO_voidSetPortDir(LCD_DPORT, 0xFF);

	LCD_voidInit();

	// Setup scene
	LCD_voidDrawData(0, GoalKeeper, 15, 0);
	LCD_voidDrawData(1, Player1, 0, 1);
	LCD_voidDrawData(2, Player2, 15, 1);
	LCD_voidDrawData(3, Ball, 1, 1);

	// Simulate ball movement
	for (u8 i = 1; i < 15; i++) {
		LCD_voidGoToxy(1, i);
		 LCD_voidSendCommand(0x01) ;            // Clear previous
		LCD_voidGoToxy(1, i + 1);
		LCD_voidSendString(3);             // Draw ball
		_delay_ms(10);
	}

	// Show "GOAL!" after reaching goalkeeper
	 LCD_voidSendCommand(0x01) ;            // Clear previous
	LCD_voidGoToxy(0, 4);
	LCD_voidSendString("GOAL!!!");

	while (1);
}
