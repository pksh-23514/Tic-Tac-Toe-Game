#include "tic_tac_toe.h"

void play_game_double (int move)
{
	char board [SIZE][SIZE];	//To store the Moves of both the Players.
	int move_count = 0;		//To count the Total number of Moves played by both the Players. It shall be less than the Total number of Cells in the Board.
	int cell_num = 0;		//To store the Cell position on the Board.
	char marker = FIRST;		//To store the Marking to be made on the particular Cell of the Board.

	initialize_board (board);	//To initialize the complete Tic-Tac-Toe board as Empty initially.

	print_board (board);		//To print the Empty Tic Tac Toe board.

	/* The loop shall run till either the Player or Computer has won the game or the number of Moves is not equal to number of Cells on the Tic Tac Toe Board. */
	while ((game_over (board) == FAILURE) && (move_count != (SIZE * SIZE)))
	{
		if (move == USER1)	//If the Current Move belongs to the User-1.
		{
			printf ("INPUT: Enter the Cell position (between 1 - 9) where USER-1 would like to mark the Move: ");
			scanf ("%d", &cell_num);	//To ask the User-1 to enter the Cell position to be marked.

			if ((cell_num < 0) || (cell_num > 9))	//Error Handling.
			{
				printf ("ERROR: Invalid Cell Position.\n");
				continue;	//To ask the User-1 to re-enter the Cell position.
			}
			else	//If the Cell position is valid, the status of the Cell position on the Board shall be checked.
			{
				if (check_cell (board, cell_num) == FAILURE)	//To check if the Cell position is Empty or Marked already.
				{
					printf ("ERROR: The Cell position is already occupied. Please enter any other Cell position.\n");
					continue;	//To ask the User-1 to re-enter the Cell position.
				}
				else
				{
					printf ("INFO: USER-1 has marked the Move as %c in the Cell position: %d.\n", marker, cell_num);

					mark_board (board, marker, cell_num);	//To mark the 'cell_num' with the 'marker' on the Board.

					print_board (board);
					move = USER2;				//To update the next Move as User-2's chance.
					marker = change_marker (marker);	//To update the Marking for the next Move by the User-2.
					move_count += 1;			//To update the number of Moves taken by 1.
				}
			}
		}
		else	//If the Current Move belongs to the User-2.
		{
			printf ("INPUT: Enter the Cell position (between 1 - 9) where USER-2 would like to mark the Move: ");
			scanf ("%d", &cell_num);	//To ask the User-2 to enter the Cell position to be marked.

			if ((cell_num < 0) || (cell_num > 9))	//Error Handling.
			{
				printf ("ERROR: Invalid Cell Position.\n");
				continue;	//To ask the User-2 to re-enter the Cell position.
			}
			else	//If the Cell position is valid, the status of the Cell position on the Board shall be checked.
			{
				if (check_cell (board, cell_num) == FAILURE)	//To check if the Cell position is Empty or Marked already.
				{
					printf ("ERROR: The Cell position is already occupied. Please enter any other Cell position.\n");
					continue;	//To ask the User-2 to re-enter the Cell position.
				}
				else
				{
					printf ("INFO: USER-2 has marked the Move as %c in the Cell position: %d.\n", marker, cell_num);

					mark_board (board, marker, cell_num);	//To mark the 'cell_num' with the 'marker' on the Board.

					print_board (board);
					move = USER1;				//To update the next Move as User-1's chance.
					marker = change_marker (marker);	//To update the Marking for the next Move by the User-1.
					move_count += 1;			//To update the number of Moves taken by 1.
				}
			}
		}
	}

	/* If the Game ended without any User winning, display the Draw message */
	if (((game_over (board)) == FAILURE) && (move_count == (SIZE * SIZE)))
		printf ("INFO: The Game ended in a Draw!\n");
	else	//Otherwise, check for the User having the Current Move.
	{
		if (move == USER1)		//If the Current Move belongs to the User-1, then User-2 has ended the Game with a Win on the Previous Move.
			printf ("INFO: USER-2 has Won the Game!\n");
		else				//If the Current Move belongs to the User-2, then User-1 has ended the Game with a Win on the Previous Move.
			printf ("INFO: USER-1 has Won the Game!\n");
	}

	return;
}
