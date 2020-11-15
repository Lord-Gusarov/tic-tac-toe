#ifndef _TTT_H_
#define _TTT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct ttt_board
{
	char **b;
	int d;
	int mvs;
	char wonBy;
	char empty;
} t_board;

/*==inside  septup_valida.c file =======*/
t_board *initBoard(int dimension, char c);
int validateIfWon(t_board *board);     /****/
int won(t_board *board);
void getPlaceNextMove(t_board *board); /****/
int endOfGame(t_board *board);

/*==inside display.c file ===============*/
void renderBoard(t_board *board);
void displayPrompt(t_board *board);
void displayWinner(t_board *board);
#endif

