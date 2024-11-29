/*
 * Tetris_Logic.h
 *
 *  Created on: Nov 27, 2024
 *      Author: Arjun
 */

#ifndef INC_TETRIS_LOGIC_H_
#define INC_TETRIS_LOGIC_H_

#include <stdio.h>
#include <stdbool.h>

#include "LCD_Driver.h"

#define U 0
#define X 1
#define K 2


#define O 0
#define I 1
#define S 2
#define Z 3
#define J 4
#define L 5
#define T 6

#define MAXWIDTH  3
#define IBLOCK_MW 4
#define OBLOCK_MW 2

#define START_POSITION_X 3
#define START_POSITION_Y 0

#define BOARD_WIDTH  10
#define BOARD_LENGTH 12

#define BOARD_W_MIN 0
#define BOARD_W_MAX 9
#define BOARD_L_MIN 0
#define BOARD_L_MAX 11

#define BOARD_MARGIN 5

#define DOWN   0
#define LEFT   1
#define RIGHT  2

#define MIN_GRID_Y 38

#define LCD_BLOCK_SIZE 22

#define LCD_X_MIN 6
#define LCD_Y_MIN 40





typedef struct {

	volatile uint8_t Name;

	volatile uint8_t Structure[4][4];

	volatile uint16_t Color;

	volatile uint8_t Width;

	volatile uint8_t Height;

	volatile int8_t XPosition;

	volatile int8_t YPosition;

	volatile uint8_t Set;

} Tetrominoe ;



Tetrominoe BuildTetrominoe(uint8_t c);
Tetrominoe RotateTetrominoe(Tetrominoe oldTetrominoe);
Tetrominoe ShiftTetrominoe(Tetrominoe tetrominoe, uint8_t dir);
void DrawBoard();
void DrawBlock(uint16_t x, uint16_t y, uint16_t color);
void DrawTetrominoe(Tetrominoe tetrominoe, uint16_t color);
bool checkSet(Tetrominoe tetrominoe);
void DrawStartScreen();



#endif /* INC_TETRIS_LOGIC_H_ */
