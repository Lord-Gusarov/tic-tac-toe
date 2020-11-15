#include "ttt.h"

void renderBoard(t_board *board)
{
	int y, x;
	char vs = '|';
	char hs = '-';

	if (board == NULL || board->b == NULL)
		return;

	printf("    ");
	for (x = 0; x < board->d; x++)
		printf("%2d  ", x);
	printf("\n");

	for (y = 0; y < board->d; y++)
	{
		printf(" %2d ", y);

		for (x = 0; x < board->d; x++)
		{
			printf(" %c ", board->b[y][x]);
			if (x < board->d - 1)
				printf("%c", vs);
		}
		printf("\n");
		if (y < board->d - 1)
		{
			printf("    ");
			for (x = 0; x < board->d; x++)
			{
				if (x < board->d - 1)
					printf("%c", hs);
				printf("%c%c%c", hs, hs, hs);
			}
			printf("\n");
		}
	}


	printf("\n");
}
