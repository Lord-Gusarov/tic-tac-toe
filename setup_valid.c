#include "ttt.h"


t_board *initBoard(int dimension, char c)
{
	int i, ii;
	t_board *board = malloc(sizeof(t_board));
	
	if (dimension > 9)
	{
		printf("\n Tic-Tac-Toe dimensions truncated to 9x9!\n\n");
		dimension = 9;
	}
	else if (dimension < 3)
	{
		printf("\n Tic-Tac-Toe dimensions increased to 3x3!\n\n");
		dimension = 3;
	}

	board->b = malloc(sizeof(char *) * dimension);
	if (board->b == NULL)
		return (NULL);
	for (i = 0; i < dimension; i++)
	{
		board->b[i] = malloc(sizeof(char) * dimension);
		if (board->b[i] == NULL)
		{
			while (i > 0)
			{
				i--;
				free(board->b[i]);
			}
			free(board);
			return (NULL);
		}
		for (ii = 0; ii < dimension; ii++)
			board->b[i][ii] = c;
	}
	board->d = dimension;
	board->mvs = 0;
	board->wonBy = '-';
	board->empty = c;

	return (board);
}

int validateIfWon(t_board *board)
{
	char c;
	int d = board->d, x, y;
	/*Horizontal Win check*/
	for (y = 0; y < d; y++)
	{
		c = board->b[y][0];
		if (c == 'X' || c == 'O')
		{
			for (x = 1; (x < d) && (board->b[y][x] == c); x++)
				;
			if (x == d)
			{
				board->wonBy = c;
				return (1);
			}
		}
	}
	/*Vertical WIN check*/
	for (x = 0; x < d; x++)
	{
		c = board->b[0][x];
		if (c == 'X' || c == 'O')
		{
			for (y = 1; (y < d) && (board->b[y][x] == c); y++)
				;
			if (y == d)
			{
				board->wonBy = c;
				return (1);
			}
		}
	}
	for(x = 0, y = 0, c = board->b[0][0]; x < d && board->b[y][x] == c; x++, y++)
		;
	if (x == d && (c == 'X' || c == 'O'))
		board->wonBy = c;
	for(x = 0, y = d - 1, c = board->b[y][0]; x < d && board->b[y][x] == c; x++, y--)
		;
	if (x == d && (c == 'X' || c == 'O'))
		board->wonBy = c;
	return (won(board));
}

int endOfGame(t_board *board)
{
	return (((won(board) == 1) || (board->mvs == (board->d * board->d))));
}

int won(t_board *board)
{
	return (!(board->wonBy == '-'));
}

void getPlaceNextMove(t_board *board)
{

	int x = 0, y = 0, sret = 0, i = 0;
	int fempty = 0;
	do {
		if(fempty)
			printf("That (x,y) coordinate has been played already!\n");
		do {
			printf(" Coordinate  x = ");
			sret = scanf("%d", &x);
			if (x <0 || x >= board->d)
				sret = - 1;
		} while (sret <= 0);

		do {
			printf(" Coordinate  y = ");
			sret = scanf("%d", &y);
			if (y <0 || y >= board->d)
				sret = - 1;
		} while (sret <= 0);
		fempty = 1;
	} while (board->b[y][x] != board->empty);
	printf("\n");
	board->b[y][x] = ((board->mvs % 2 == 0) ? 'X': 'O');
	board->mvs++;
}
