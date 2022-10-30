#include "tic_tac_toe.h"

/* Minimax Algorithm Implementation */

int calculate_score (char board [SIZE][SIZE], char marker, int move_count, int move)
{
	int score = 0;
	int best = 0;	//To store the Best Score.

	if ((game_over (board)) == SUCCESS)		//If the Game is Over, the Player having the Last Move has Won and similarly, the Score value shall be returned.
	{
		if (move == COMPUTER)	//If the Current move is of Computer, User has Won as the Last Move was played by User i.e. Worst Move.
			return -100;

		if (move == USER)	//If the Current move is of User, Computer has Won as the Last Move was played by Computer i.e. Best Move.
			return 100;
	}
	else	//The Game can be Over or not depending on the number of Moves played on the Board.
	{
		if (move_count < 9)		//The Game is not Over as Moves are still left and there are other possible scenarios to be checked for the Best Score calculation.
		{
			if (move == COMPUTER)	//Simulate the Moves taken by Computer till the Game is Over.
			{
				best = INT_MIN;	//Start the Best Score as the Least Value possible as we have to Maximize the Score for Computer.

				for (int i = 1; i <= (SIZE * SIZE); i++)
				{
					if (check_cell (board, i) == SUCCESS)	//If the Cell position is empty, it will be Marked by the Computer.
					{
						mark_board (board, marker, i);
						marker = change_marker (marker);
						score = calculate_score (board, marker, (move_count + 1), USER);
						demark_board (board, i);
						
						if (score > best)	//If the Calculated Score is greater than the Best Score; update the Best Score.
							best = score;
					}
				}

				return best;	//Return the Best Score of Computer i.e. Maximizer.
			}
			else	//Simulate the Moves taken by User till the Game is Over.
			{
				best = INT_MAX;	//Start the Best Score as the Highest Value possible as we have to Minimize the Score for User.

				for (int i = 1; i <= (SIZE * SIZE); i++)
				{
					if (check_cell (board, i) == SUCCESS)	//If the Cell position is empty, it will be Marked by the User.
					{
						mark_board (board, marker, i);
						marker = change_marker (marker);
						score = calculate_score (board, marker, (move_count + 1), COMPUTER);
						demark_board (board, i);

						if (score < best)	//If the Calculated Score is smaller than the Best Score; update the Best Score for User.
							best = score;
					}
				}

				return best;	//Return the Best Score of User i.e. Minimizer.
			}
		}
		else	//The Game is Over and no Player has Won i.e. it's a Draw.
		{
			return 0;
		}
	}
}
