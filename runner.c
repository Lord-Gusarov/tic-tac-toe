#include "ttt.h"

/**
 * main - takes care of running the game
 * Return: 0 if succefully payed and exited
 */
int main(void)
{
	t_board *board = NULL;
	int dimension = 1;

	board = initBoard(dimension, ' ');
	renderBoard(board);

	while (!endOfGame(board))
	{
		/*displayPrompt(board); */
		getPlaceNextMove(board);
		renderBoard(board);
		validateIfWon(board);
	}

	if (won(board))
	{
		printf("We have a winner");
		/*displayWinner(board);*/
	}
	else
		printf("\tIt's a DRAW!!\n");
/*
	if(board)
		freeTTT(board);
*/

	return (0);
}
