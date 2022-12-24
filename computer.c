#include "tic_tac_toe.h"

/* 
   To calculate the Best possible Move to be played by the Computer in One-Player Option.
   Input - The Board Array, the Current Marker and the Number of Moves already played in the Game.
   Output - The Cell position for the Best possible Move.
 */
int optimized_move (char board [SIZE][SIZE], char marker, int move_count)
{
	int pos = -1;				//Random Cell position to be Marked by the Computer.
	int max_score = INT_MIN;	//Random Best Score for the Move to be taken by the Computer.
	int curr_score;

	for (int i = 1; i <= (SIZE * SIZE); i++)
	{
		if (check_cell (board, i) == SUCCESS)	//If the Cell position is empty, it will be Marked by the Computer.
		{
			mark_board (board, marker, i);		//Mark the particular Cell position with the Marker of the Computer.

			marker = change_marker (marker);	//Update the Marker for the next Move by the User.

			curr_score = calculate_score (board, marker, (move_count + 1), USER);	//Calculate the Score for the Current Move by the Computer through Minimax Algorithm.

			demark_board (board, i);		//Since, we are Backtracking every Move; the Move done initially to calculate the Score shall be undone.

			if (curr_score > max_score)		//If the Current Move Score is greater than the Maximum Score; update the Cell position and Maximum Score.
			{
				max_score = curr_score;
				pos = i;
			}
		}
	}

	return pos;		//Return the Best Possible Move by the Computer.
}
