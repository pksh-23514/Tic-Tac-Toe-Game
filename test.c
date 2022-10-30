#include "tic_tac_toe.h"

void run_tests ()
{
	printf ("Testing for the Code Begins!\n");

	/* Test File: board.c */

	/* Testing for Initializing and Printing the Board */
	char board [SIZE][SIZE];
	initialize_board (board);
	print_board (board);

	/* Testing for Checking the Status of a given Cell position on the Board */
	for (int i = 1; i <= (SIZE * SIZE); i++)
	{
		if (check_cell (board, i) == SUCCESS)
			printf ("Empty Cell: %d\t", i);
	}
	printf ("\n");

	/* Testing for Changing the Marker and Marking the Board */
	char marker = FIRST;
	for (int i = 1; i <= (SIZE * SIZE); i++)
	{
		mark_board (board, marker, i);
		marker = change_marker (marker);
	}
	print_board (board);

	/* Testing for Demarking the Board */
	for (int i = 1; i <= (SIZE * SIZE); i++)
	{
		demark_board (board, i);
	}
	print_board (board);

	/* Testing for the Ways in which the Game can be Over */
	marker = FIRST;

	for (int i = 1; i <= SIZE; i++)				//Horizontal Win for the Player.
		mark_board (board, marker, i);
	print_board (board);
	if ((game_over (board)) == SUCCESS)
		printf ("Game Over!\n");
	initialize_board (board);

	for (int i = 1; i <= (SIZE * SIZE); i += 3)		//Vertical Win for the Player.
		mark_board (board, marker, i);
	print_board (board);
	if ((game_over (board)) == SUCCESS)
		printf ("Game Over!\n");
	initialize_board (board);

	for (int i = 1; i <= (SIZE * SIZE); i += 4)		//Diagonal Win for the Player.
		mark_board (board, marker, i);
	print_board (board);
	if ((game_over (board)) == SUCCESS)
		printf ("Game Over!\n");

	/* Test File: single_player.c */

	//play_game_single (USER);

	return;
}
