#include "tic_tac_toe.h"

/*
   To Initialize the Tic-Tac-Toe at the Start of a New game and provide the Instructions to the User.
   Input - The Board Array.
   Output - NIL.
 */
void initialize_board (char board [SIZE][SIZE])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board [i][j] = '*';
		}
	}

	printf ("\t\t\t\t\t\t INSTRUCTIONS\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	printf ("INFO: While playing your Turn; please enter the Cell number between 1-9 to choose the Cell to mark your Move.\n");
	printf ("INFO: The Cells are numbered 1 to 9 sequentially Row-wise.\n");
	printf ("INFO: The Markers are as follows: '*' -> Empty Cell, 'X' / 'O' -> Filled Cell.\n");
	printf("---------------------------------------------------------------------------------------------------------------\n");
	return;
}

/*
   To Display the Current Status of the Tic-Tac-Toe Board.
   Input - The Board Array.
   Output - NIL.
 */
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
	printf ("\n");

	return;
}

/*
   To Check if a Particular Cell on the Tic-Tac-Toe Board is Empty or not.
   Input - The Board Array and the Cell Position.
   Output - SUCCESS or FAILURE.
 */
int check_cell (char board [SIZE][SIZE], int pos)
{
	int row = (pos - 1) / SIZE;		//To get the Row position of the Cell on the Board.
	int col = (pos - 1) % SIZE;		//To get the Column position of the Cell on the Board.

	if (board [row][col] == '*')		//If the give Cell is marked as '*', then it is Empty.
		return SUCCESS;
	else
		return FAILURE;
}

/*
   To Mark a Particular Cell on the Tic-Tac-Toe Board.
   Input - The Board Array, the Marker of the User and the Cell Position.
   Output - NIL.
 */
void mark_board (char board [SIZE][SIZE], char marker, int pos)
{
	int row = (pos - 1) / SIZE;		//To get the Row position of the Cell on the Board.
	int col = (pos - 1) % SIZE;		//To get the Column position of the Cell on the Board.

	board [row][col] = marker;		//To mark the Particular Cell position on the Board with the given Marking.
	return;
}

/*
   To De-Mark a Particular Cell on the Tic-Tac-Toe Board.
   Input - The Board Array and the Cell Position.
   Output - NIL.
 */
void demark_board (char board [SIZE][SIZE], int pos)
{
	int row = (pos - 1) / SIZE;		//To get the Row position of the Cell on the Board.
	int col = (pos - 1) % SIZE;		//To get the Column position of the Cell on the Board.

	board [row][col] = '*';			//To de-mark the Particular Cell position on the Board.
	return;
}

/*
   To Update the Marker of the Users for the next Move.
   Input - The Current User's Marker.
   Output - The Next User's Marker.
 */
char change_marker (char marker)
{
	if (marker == FIRST)			//If the Current Marker belongs to the User-1; switch the Marker to User-2.
		marker = SECOND;
	else					//If the Current Marker belongs to the User-2; switch the Marker to User-1.
		marker = FIRST;
	return marker;
}

/*
   To Check if a Particular User has won the Game by marking all the Cells in a Particular Row.
   Input - The Board Array.
   Output - SUCCESS or FAILURE.
 */
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

/*
   To Check if a Particular User has won the Game by marking all the Cells in a Particular Column.
   Input - The Board Array.
    Output - SUCCESS or FAILURE.
 */
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

/*
   To Check if a Particular User has won the Game by marking all the Cells in the Principal or Counter Diagonal.
   Input - The Board Array.
   Output - SUCCESS or FAILURE.
 */
int diagonal_win (char board [SIZE][SIZE])
{
	/* If any of the Player marks all the cells along the Principal Diagonal on the Board */
	if ((board [0][0] == board [1][1]) && (board [1][1] == board [2][2]) && (board [0][0] != '*'))
		return SUCCESS;

	/* If any of the Player marks all the cells along the Counter Diagonal on the Board */
	if ((board [0][2] == board [1][1]) && (board [1][1] == board [2][0]) && (board [0][2] != '*'))
		return SUCCESS;

	return FAILURE;
}

/*
   To Check if the Game has ended by any particular Means of Win defined above.
   Input - The Board Array.
   Output - SUCCESS or FAILURE.
 */
int game_over (char board [SIZE][SIZE])
{
	/* The Array of Function pointers shall act as a means to call the various functions check if the Game has ended or not */
	int (*win [3]) (char [SIZE][SIZE]) = {&row_win, &col_win, &diagonal_win};

	for (int i = 0; i < 3; i++)
	{
		if (((*win [i]) (board)) == SUCCESS)	//If any of the function call returns SUCCESS, the Game is Over.
			return SUCCESS;
	}

	return FAILURE;
}
