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

int row_win (char board [SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		/* If any of the Player marks all the cells of a particular Row on the Board */
		if ((board [i][0] == board [i][1]) && (board [i][1] == board [i][2]) && (board [i][0] != '*'))
			return SUCCESS;
	}

	return FAILURE;
}

int col_win (char board [SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		/* If any of the Player marks all the cells of a particular Column on the Board */
		if ((board [0][i] == board [1][i]) && (board [1][i] == board [2][i]) && (board [0][i] != '*'))
			return SUCCESS;
	}

	return FAILURE;
}

int diagonal_win (char board [SIZE][SIZE])
{
	/* If any of the Player marks all the cells along the Principal Diagonal on the Board */
	if ((board [0][0] == board [1][1]) && (board [1][1] == board [2][2]) && (board [0][0] != '*'))
		return SUCCESS;

	if ((board [0][2] == board [1][1]) && (board [1][1] == board [2][0]) && (board [0][2] != '*'))
		return SUCCESS;

	return FAILURE;
}

int game_over (char board [SIZE][SIZE])
{
	int (*win [3]) (char [SIZE][SIZE]) = {&row_win, &col_win, &diagonal_win};	//If a Player wins the game by any of the above means; the Game is Over.

	for (int i = 0; i < 3; i++)
	{
		if (((*win [i]) (board)) == SUCCESS)	//If any of the function call returns SUCCESS, the Game is Over.
			return SUCCESS;
	}

	return FAILURE;
}
