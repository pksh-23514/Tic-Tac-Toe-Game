#include "tic_tac_toe.h"

void play_game_single (int move)
{
	char board [SIZE][SIZE];	//To store the Moves of both the Players.
	int move_count = 0;		//To count the Total number of Moves played by both the Players. It shall be less than the Total number of Cells in the Board.
	int cell_num = 0;		//To store the Cell position on the Board.
	char marker = FIRST;		//To store the Marking to be made on the particular Cell of the Board.

	initialize_board (board);	//To initialize the complete Tic Tac Toe board as Empty initially.

	print_board (board);		//To print the Empty Tic Tac Toe board.

	/* The loop shall run till either the Player or Computer has won the game or the number of Moves is not equal to number of Cells on the Tic Tac Toe Board. */
	while ((game_over (board) == FAILURE) && (move_count != (SIZE * SIZE)))
	{
		if (move == USER)	//If the Current Move belongs to the User.
		{
			printf ("INPUT: Enter the Cell position (between 1 - 9) where you would like to mark your Move: ");
			scanf ("%d", &cell_num);	//To ask the User to enter the Cell position to be marked.

			if ((cell_num < 0) || (cell_num > 9))	//Error Handling.
			{
				printf ("ERROR: Invalid Cell Position.\n");
				continue;	//To ask the User to re-enter the Cell position.
			}
			else	//If the Cell position is valid, the status of the Cell position on the Board shall be checked.
			{
				if (check_cell (board, cell_num) == FAILURE)	//To check if the Cell position is Empty or Marked already.
				{
					printf ("ERROR: The Cell position is already occupied. Please enter any other Cell position.\n");
					continue;	//To ask the User to re-enter the Cell position.
				}
				else
				{
					printf ("INFO: You have marked your Move as %c in the Cell position: %d.\n", marker, cell_num);

					mark_board (board, marker, cell_num);	//To mark the 'cell_num' with the 'marker' on the Board.

					print_board (board);
					move = COMPUTER;			//To update the next Move as Computer's chance.
					marker = change_marker (marker);	//To update the Marking for the next Move by the Computer.
					move_count += 1;			//To update the number of Moves taken by 1.
				}
			}
		}
		else	//If the Current Move belongs to the Computer.
		{
			cell_num = optimized_move (board, marker, move_count);	//To check which Move by Computer will only lead to Win or Draw for the Computer.

			printf ("INFO: The COMPUTER has marked the Move as %c in the Cell position: %d.\n", marker, cell_num);

			mark_board (board, marker, cell_num);	//To mark the 'cell_num' with the 'marker' on the Board.

			print_board (board);
			move = USER;				//To update the next Move as User's chance.
			marker = change_marker (marker);	//To update the Marking for the next Move by the User.
			move_count += 1;			//To update the number of Moves taken by 1.
		}
	}

	if (((game_over (board)) == FAILURE) && (move_count == (SIZE * SIZE)))
		printf ("INFO: The Game ended in a Draw!\n");
	else
	{
		if (move == COMPUTER)
			printf ("INFO: YOU have Won the Game!\n");
		else
			printf ("INFO: COMPUTER has Won the Game!\n");
	}

	return;
}
