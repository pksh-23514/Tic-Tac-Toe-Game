#include "tic_tac_toe.h"

void initialize_board (char board [SIZE][SIZE])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board [i][j] = '*';
		}
	}

	printf ("INFO: While playing your Turn; please enter the Cell number between 1 - 9 to choose the Cell in which you want to mark your Move.\n");
	printf ("INFO: The Cells are numbered 1 to 9 sequentially Row-wise.\n");
	printf ("INFO: The Markers are as follows: '*' -> Empty Cell, 'X' / 'O' -> Filled Cell.\n");
	return;
}

void print_board (char board [SIZE][SIZE])
{
	printf ("INFO: The Current Board Status is:\n");
	printf ("-------------\n");
	for (int i = 0; i < 3; i++)
	{
		printf ("| ");
		for (int j = 0; j < 3; j++)
		{
			printf ("%c | ", board [i][j]);
		}

		printf ("\n-------------\n");
	}

	return;
}

int check_cell (char board [SIZE][SIZE], int pos)
{
	int row = (pos - 1) / SIZE;		//To get the Row position of the Cell on the Board.
	int col = (pos - 1) % SIZE;		//To get the Column position of the Cell on the Board.

	if (board [row][col] == '*')	//If the give Cell is marked as '*', then it is Empty.
		return SUCCESS;
	else
		return FAILURE;
}

void mark_board (char board [SIZE][SIZE], char marker, int pos)
{
	int row = (pos - 1) / SIZE;
	int col = (pos - 1) % SIZE;

	board [row][col] = marker;	//To mark the Particular Cell position on the Board with the given Marking.
	return;
}

void demark_board (char board [SIZE][SIZE], int pos)
{
	int row = (pos - 1) / SIZE;
	int col = (pos - 1) % SIZE;

	board [row][col] = '*';		//To de-mark the Particular Cell position on the Board.
	return;
}

char change_marker (char marker)
{
	if (marker == FIRST)	//To update the Marking for the next Move.
		marker = SECOND;
	else
		marker = FIRST;
	return marker;
}
