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
				tetrominoe.Width = 2;
				tetrominoe.Height = 2;

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
				tetrominoe.Width = 4;
				tetrominoe.Height = 1;

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
				tetrominoe.Width = 3;
				tetrominoe.Height = 2;

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
				tetrominoe.Width = 3;
				tetrominoe.Height = 2;

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
				tetrominoe.Color = LCD_COLOR_ORANGE;
				tetrominoe.Width = 2;
				tetrominoe.Height = 3;

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
				tetrominoe.Width = 2;
				tetrominoe.Height = 3;

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
				tetrominoe.Width = 3;
				tetrominoe.Height = 2;

				break;

			default:
				;

	}

	tetrominoe.XPosition = START_POSITION_X;
	tetrominoe.YPosition = START_POSITION_Y;
	tetrominoe.Set = U;


	DrawTetrominoe(tetrominoe, tetrominoe.Color);


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
	newTetrominoe.Width = oldTetrominoe.Height;
	newTetrominoe.Height = oldTetrominoe.Width;
	newTetrominoe.XPosition = oldTetrominoe.XPosition;
	newTetrominoe.YPosition = oldTetrominoe.YPosition;
	newTetrominoe.Set = oldTetrominoe.Set;


	if(oldTetrominoe.XPosition + oldTetrominoe.Height > BOARD_W_MAX){

		newTetrominoe.XPosition = BOARD_WIDTH - oldTetrominoe.Height;

	}

	else if(oldTetrominoe.XPosition - oldTetrominoe.Height < BOARD_W_MIN - X){

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


	DrawTetrominoe(newTetrominoe, newTetrominoe.Color);


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
	newTetrominoe.Width = oldTetrominoe.Width;
	newTetrominoe.Height = oldTetrominoe.Height;
	newTetrominoe.XPosition = oldTetrominoe.XPosition;
	newTetrominoe.YPosition = oldTetrominoe.YPosition;
	newTetrominoe.Set = oldTetrominoe.Set;


	switch(dir){

	case DOWN:

		if(oldTetrominoe.YPosition > BOARD_L_MAX - oldTetrominoe.Height){

			int temp = 0;

			for(int k = 0; k < 4; k++){
				temp += oldTetrominoe.Structure[BOARD_L_MAX - oldTetrominoe.YPosition - X][k];
			}

			if(temp == 0){
				newTetrominoe.YPosition = oldTetrominoe.YPosition + X;
			}
		}

		else if(oldTetrominoe.YPosition <= BOARD_L_MAX - oldTetrominoe.Height){

			newTetrominoe.YPosition = oldTetrominoe.YPosition + X;
		}



		break;

	case LEFT:

		if(oldTetrominoe.XPosition == BOARD_W_MIN){

			int temp = 0;

			for(int k = 0; k < 4; k++){
				temp += oldTetrominoe.Structure[k][oldTetrominoe.XPosition];
			}

			if(temp == 0){

				newTetrominoe.XPosition = oldTetrominoe.XPosition - X;

			}

		}

		else if(oldTetrominoe.XPosition > BOARD_W_MIN){

			newTetrominoe.XPosition = oldTetrominoe.XPosition - X;

		}

		break;

	case RIGHT:

		if(oldTetrominoe.XPosition >= BOARD_W_MAX - oldTetrominoe.Width){

			int temp = 0;

			for(int k = 0; k < 4; k++){
				temp += oldTetrominoe.Structure[k][BOARD_W_MAX - oldTetrominoe.XPosition];
			}

			if(temp == 0){

				newTetrominoe.XPosition = oldTetrominoe.XPosition + 1;

			}

		}

		else if(oldTetrominoe.XPosition < BOARD_W_MAX - oldTetrominoe.Width){

			newTetrominoe.XPosition = oldTetrominoe.XPosition + X;

		}

		break;

	default:
		;

	}


	DrawTetrominoe(newTetrominoe, newTetrominoe.Color);


	return newTetrominoe;

}


void DrawBoard(Board b){

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



	for(int k = 1; k <= BOARD_LENGTH + 1; k++){
		for(int l = 0; l <= BOARD_WIDTH + 1; l++){

			switch(b.Field[k][l]){

			case O:
				DrawBlock(l-1, k-1, LCD_COLOR_YELLOW);
				break;

			case I:
				DrawBlock(l-1, k-1, LCD_COLOR_CYAN);
				break;

			case S:
				DrawBlock(l-1, k-1, LCD_COLOR_GREEN);
				break;

			case Z:
				DrawBlock(l-1, k-1, LCD_COLOR_RED);
				break;

			case J:
				DrawBlock(l-1, k-1, LCD_COLOR_ORANGE);
				break;

			case L:
				DrawBlock(l-1, k-1, LCD_COLOR_MAGENTA);
				break;

			case T:
				DrawBlock(l-1, k-1, LCD_COLOR_BLUE2);
				break;


			}
		}
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


//bool checkBoard(Tetrominoe tetrominoe, uint8_t board[][]){
//
//	for(int i = 0; i < 4; i++){
//		for(int j = 0; j < 4; j++){
//
//			if(tetrominoe.Structure[i][j] == X && board[i + X][j] == K){
//
//				board[i][j] = K;
//
//			}
//
//		}
//	}
//
//}


void DrawStartScreen(Board b){

	DrawBoard(b);

	Tetrominoe t = {0};

	t = BuildTetrominoe(L);

	HAL_Delay(100);

	for(int i = 0; i < 4; i++){
		t = ShiftTetrominoe(t, LEFT);
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	for(int i = 0; i < 5; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(I);

	HAL_Delay(100);

	t = RotateTetrominoe(t);

	HAL_Delay(100);

	for(int i = 0; i < 6; i++){
		t = ShiftTetrominoe(t, RIGHT);
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	for(int i = 0; i < 2; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(Z);

	for(int i = 0; i < 2; i++){
		t = ShiftTetrominoe(t, DOWN);
		t = ShiftTetrominoe(t, LEFT);

		HAL_Delay(100);
	}

	for(int i = 0; i < 8; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(J);

	for(int i = 0; i < 4; i++){
		t = ShiftTetrominoe(t, DOWN);
		t = ShiftTetrominoe(t, RIGHT);

		HAL_Delay(100);
	}

	for(int i = 0; i < 5; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(S);

	HAL_Delay(100);

	t = ShiftTetrominoe(t, LEFT);

	HAL_Delay(100);

	for(int i = 0; i < 3; i++){
		t = ShiftTetrominoe(t, DOWN);
		t = RotateTetrominoe(t);

		HAL_Delay(100);
	}

	for(int i = 0; i < 5; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(O);

	HAL_Delay(100);

	t = ShiftTetrominoe(t, RIGHT);

	HAL_Delay(100);

	for(int i = 0; i < 10; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}

	t = BuildTetrominoe(T);

	HAL_Delay(100);

	t = ShiftTetrominoe(t, DOWN);

	HAL_Delay(100);

	for(int i = 0; i < 2; i++){
		t = ShiftTetrominoe(t, RIGHT);


		HAL_Delay(100);
	}

	for(int i = 0; i < 5; i++){
		t = RotateTetrominoe(t);

		HAL_Delay(100);
	}

	for(int i = 0; i < 8; i++){
		t = ShiftTetrominoe(t, DOWN);

		HAL_Delay(100);
	}



	for(int i = 29; i < 212; i++){
		LCD_Draw_Vertical_Line(i, 63, 137, LCD_COLOR_MAGENTA);
	}

	for(int i = 51; i < 190; i++){
		LCD_Draw_Vertical_Line(i, 85, 93, LCD_COLOR_BLACK);
	}

	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font16x24);

	LCD_DisplayChar(80, 100, 'T');
	LCD_DisplayChar(95, 100, 'E');
	LCD_DisplayChar(110, 100, 'T');
	LCD_DisplayChar(125, 100, 'R');
	LCD_DisplayChar(135, 100, 'I');
	LCD_DisplayChar(145, 100, 'S');


	LCD_SetTextColor(LCD_COLOR_WHITE);
	LCD_SetFont(&Font12x12);

	LCD_DisplayChar(70, 150, 'T');
	LCD_DisplayChar(80, 150, 'a');
	LCD_DisplayChar(90, 150, 'p');

	LCD_DisplayChar(110, 150, 'T');
	LCD_DisplayChar(120, 150, 'o');

	LCD_DisplayChar(140, 150, 'P');
	LCD_DisplayChar(150, 150, 'l');
	LCD_DisplayChar(155, 150, 'a');
	LCD_DisplayChar(165, 150, 'y');

}


Board InitBoard(){

	Board new = {U};

	for(int i = 0; i <= BOARD_LENGTH + 1; i++){
		new.Field[i][0] = K;
		new.Field[i][BOARD_WIDTH + 1] = K;
	}

	for(int i = 1; i <= BOARD_WIDTH; i++){
		new.Field[0][i] = K;
		new.Field[BOARD_LENGTH + 1][i] = K;
	}


	DrawBoard(new);

	return new;

}


//Board UpdateBoard(Tetrominoe t, Board b){
//
//	int8_t x = t.XPosition;
//	int8_t y = t.YPosition;
//
//	for(int i = 0; i < 4; i++){
//		for(int j = 0; j < 4; j++){
//
//			if(t.Structure[i][j] == X){
//				b.Field[x + i][y + j] = t.Name;
//			}
//
//		}
//	}
//
//	DrawBoard(b);
//
//	return b;
//
//}


Board SetTetrominoe(Tetrominoe t, Board b){

	int8_t x = t.XPosition;
	int8_t y = t.YPosition;

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){

			if(t.Structure[i][j] == X){
				b.Field[x + i][y + j] = t.Name;
			}

		}
	}

	DrawBoard(b);

	return b;

}