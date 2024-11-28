/*
 * Tetris_Logic.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Arjun
 */

#include "Tetris_Logic.h"



Tetrominoe BuildTetrominoe(uint8_t c){

	Tetrominoe tetrominoe = {0};

	switch(c){

			case O:

				bool blk0[4][4] = {{X, X, U, U},
								   {X, X, U, U},
								   {U, U, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk0[i][j];

					}
				}


				tetrominoe.Name = O;
				tetrominoe.Color = LCD_COLOR_YELLOW;
				tetrominoe.MaxWidth = OBLOCK_MW;

				break;


			case I:

				bool blk1[4][4] = {{X, X, X, X},
								   {U, U, U, U},
								   {U, U, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 4; i++){
					for(int j = 0; j < 4; j++){

						tetrominoe.Structure[i][j] = blk1[i][j];

					}
				}


				tetrominoe.Name = I;
				tetrominoe.Color = LCD_COLOR_CYAN;
				tetrominoe.MaxWidth = IBLOCK_MW;

				break;


			case S:

				bool blk2[4][4] = {{U, X, X, U},
								   {X, X, U, U},
								   {U, U, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk2[i][j];

					}
				}


				tetrominoe.Name = S;
				tetrominoe.Color = LCD_COLOR_GREEN;
				tetrominoe.MaxWidth = MAXWIDTH;

				break;


			case Z:

				bool blk3[4][4] = {{X, X, U, U},
								   {U, X, X, U},
								   {U, U, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk3[i][j];

					}
				}


				tetrominoe.Name = Z;
				tetrominoe.Color = LCD_COLOR_RED;
				tetrominoe.MaxWidth = MAXWIDTH;

				break;


			case J:

				bool blk4[4][4] = {{U, X, U, U},
								   {U, X, U, U},
								   {X, X, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk4[i][j];

					}
				}


				tetrominoe.Name = J;
				tetrominoe.Color = LCD_COLOR_BLUE;
				tetrominoe.MaxWidth = MAXWIDTH;

				break;


			case L:

				bool blk5[4][4] = {{U, X, U, U},
								   {U, X, U, U},
								   {U, X, X, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk5[i][j];

					}
				}


				tetrominoe.Name = L;
				tetrominoe.Color = LCD_COLOR_MAGENTA;
				tetrominoe.MaxWidth = MAXWIDTH;

				break;


			case T:

				bool blk6[4][4] = {{U, X, U, U},
								   {X, X, X, U},
								   {U, U, U, U},
								   {U, U, U, U}};

				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){

						tetrominoe.Structure[i][j] = blk6[i][j];

					}
				}


				tetrominoe.Name = T;
				tetrominoe.Color = LCD_COLOR_BLUE2;
				tetrominoe.MaxWidth = MAXWIDTH;

				break;

			default:
				;

	}

	tetrominoe.XPosition = START_POSITION_X;
	tetrominoe.YPosition = START_POSITION_Y;


	return tetrominoe;

}


Tetrominoe RotateTetrominoe(Tetrominoe oldTetrominoe){


	if(oldTetrominoe.Name == O){
		return oldTetrominoe;
	}



	DrawTetrominoe(oldTetrominoe, LCD_COLOR_BLACK);


	Tetrominoe newTetrominoe = {0};

	newTetrominoe.Name = oldTetrominoe.Name;
	newTetrominoe.Color = oldTetrominoe.Color;
	newTetrominoe.MaxWidth = oldTetrominoe.MaxWidth;
	newTetrominoe.XPosition = oldTetrominoe.XPosition;
	newTetrominoe.YPosition = oldTetrominoe.YPosition;


	if(oldTetrominoe.XPosition + oldTetrominoe.MaxWidth > BOARD_W_MAX){

		newTetrominoe.XPosition = BOARD_WIDTH - oldTetrominoe.MaxWidth;

	}

	else if(oldTetrominoe.XPosition - oldTetrominoe.MaxWidth < BOARD_W_MIN){

		newTetrominoe.XPosition = U;

	}


	if(oldTetrominoe.Name == I){

		uint8_t transpose4[4][4];

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){

				transpose4[i][j] = oldTetrominoe.Structure[j][i];

			}
		}


		for(int k = 0; k < 4; k++){
			for(int l = 0; l < 4; l++){

				newTetrominoe.Structure[k][l] = transpose4[k][l];

			}
		}

	}

	else if(oldTetrominoe.Name != O){

		uint8_t transpose3[3][3];
		uint8_t transformed[3][3];

		uint8_t hm_identity[3][3] = {{U, U, X},
									 {U, X, U},
									 {X, U, U}};


		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){

				transpose3[i][j] = oldTetrominoe.Structure[j][i];

			}
		}


		for(int m = 0; m < 3; m++){
			for(int n = 0; n < 3; n++){

				transformed[m][n] = 0;

				for(int p = 0; p < 3; p++){

					transformed[m][n] += (transpose3[m][p] * hm_identity[p][n]);

				}
			}
		}


		for(int k = 0; k < 4; k++){
			for(int l = 0; l < 4; l++){

				if(k == 3 || l == 3){

					newTetrominoe.Structure[k][l] = U;

				}

				else{

					newTetrominoe.Structure[k][l] = transformed[k][l];

				}

			}
		}

	}


	return newTetrominoe;

}


Tetrominoe ShiftTetrominoe(Tetrominoe oldTetrominoe, uint8_t dir){

	DrawTetrominoe(oldTetrominoe, LCD_COLOR_BLACK);

	Tetrominoe newTetrominoe = {0};

	newTetrominoe.Name = oldTetrominoe.Name;

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			newTetrominoe.Structure[i][j] = oldTetrominoe.Structure[i][j];
		}
	}

	newTetrominoe.Color = oldTetrominoe.Color;
	newTetrominoe.MaxWidth = oldTetrominoe.MaxWidth;
	newTetrominoe.XPosition = oldTetrominoe.XPosition;
	newTetrominoe.YPosition = oldTetrominoe.YPosition;


	switch(dir){

	case DOWN:

		newTetrominoe.YPosition = oldTetrominoe.YPosition + X;

		break;

	case LEFT:

		if(oldTetrominoe.XPosition == BOARD_W_MIN){

			int temp = 0;

			for(int k = 0; k < 4; k++){
				temp += oldTetrominoe.Structure[k][oldTetrominoe.XPosition];
			}

			if(temp == 0){

				newTetrominoe.XPosition = -1;

			}

		}

		else if(oldTetrominoe.XPosition > BOARD_W_MIN){

			newTetrominoe.XPosition = oldTetrominoe.XPosition - X;

		}

		break;

	case RIGHT:

		if(oldTetrominoe.XPosition >= BOARD_W_MAX - oldTetrominoe.MaxWidth){

			int temp = 0;

			for(int k = 0; k < 4; k++){
				temp += oldTetrominoe.Structure[k][BOARD_W_MAX - oldTetrominoe.XPosition];
			}

			if(temp == 0){

				newTetrominoe.XPosition = oldTetrominoe.XPosition + 1;

			}

		}

		else if(oldTetrominoe.XPosition < BOARD_W_MAX - oldTetrominoe.MaxWidth){

			newTetrominoe.XPosition = oldTetrominoe.XPosition + X;

		}

		break;

	default:
		;

	}


	return newTetrominoe;

}


void DrawBoard(){

	LCD_Clear(0, LCD_COLOR_BLACK);

	for(uint16_t i = U; i <= BOARD_MARGIN; i++){

		LCD_Draw_Vertical_Line(i, MIN_GRID_Y, LCD_PIXEL_HEIGHT - MIN_GRID_Y, LCD_COLOR_WHITE);
		LCD_Draw_Vertical_Line((LCD_PIXEL_WIDTH - i), MIN_GRID_Y, LCD_PIXEL_HEIGHT - MIN_GRID_Y, LCD_COLOR_WHITE);

	}


	for(uint16_t i = BOARD_MARGIN + LCD_BLOCK_SIZE + X; i < LCD_PIXEL_WIDTH - BOARD_MARGIN; i += LCD_BLOCK_SIZE + X){

		LCD_Draw_Vertical_Line(i, MIN_GRID_Y + X, LCD_PIXEL_HEIGHT - MIN_GRID_Y, LCD_COLOR_WHITE);

	}


	for(uint16_t j = LCD_PIXEL_HEIGHT; j >= LCD_PIXEL_HEIGHT - BOARD_MARGIN; j--){

		LCD_Draw_Horizontal_Line(U, j, LCD_PIXEL_WIDTH, LCD_COLOR_WHITE);
		LCD_Draw_Horizontal_Line(U, j - LCD_PIXEL_HEIGHT + MIN_GRID_Y + X, LCD_PIXEL_WIDTH, LCD_COLOR_WHITE);

	}


	for(uint16_t j = MIN_GRID_Y + X; j < LCD_PIXEL_HEIGHT - BOARD_MARGIN; j += LCD_BLOCK_SIZE + X){

		LCD_Draw_Horizontal_Line(U, j, LCD_PIXEL_WIDTH, LCD_COLOR_WHITE);

	}

}


void DrawBlock(uint16_t x, uint16_t y, uint16_t color){

	uint16_t startX = LCD_X_MIN + x*(LCD_BLOCK_SIZE + X);
	uint16_t endX = startX + LCD_BLOCK_SIZE;

	uint16_t startY = LCD_Y_MIN + y*(LCD_BLOCK_SIZE + X);


	for(uint16_t k = startX; k < endX; k++){

		LCD_Draw_Vertical_Line(k, startY, LCD_BLOCK_SIZE, color);
	}

}


void DrawTetrominoe(Tetrominoe tetrominoe, uint16_t color){

	int x = tetrominoe.XPosition;
	int y = tetrominoe.YPosition;



	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){

			if(tetrominoe.Structure[i][j] == X){

				DrawBlock(x + j, y + i, color);

			}

		}
	}

}


//bool checkSet(Tetrominoe tetrominoe){
//
//	for(int i = 0; i < 4; i++){
//		for(int j = 0; j < 4; j++){
//
//			return true;
//
//		}
//	}
//
//}
