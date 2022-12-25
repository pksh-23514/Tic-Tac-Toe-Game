#include "tic_tac_toe.h"
/*
   To Implement the Minimax Algorithm for calculating the Best possible Move for the Computer in Single Player option.
   Input - The Board Array, the Current Marker, the Number of Moves already played in the Game and which Player has to Mark on the Board on the Current Move.
   Output - Returns the Maximum value for the Computer, Minimum value for the User and 0 if the Game is Over.
 */
int calculate_score (char board [SIZE][SIZE], char marker, int move_count, int move)
{
	int score = 0;
	int best = 0;	//To store the Best possible Score.

	if ((game_over (board)) == SUCCESS)	//If the Game is Over, the Player having the Last Move has Won and similarly, the Score value shall be returned.
	{
		if (move == COMPUTER)		//If the Current move is of Computer, User has Won as the Last Move was played by User i.e. Worst Move.
			return -100;

		if (move == USER)		//If the Current move is of User, Computer has Won as the Last Move was played by Computer i.e. Best Move.
			return 100;
	}
	else	//The Game can be Over or not depending on the number of Moves played on the Board.
	{
		if (move_count < 9)	//The Game is not Over as Moves are still left and there are other possible scenarios to be checked for the Best Score calculation.
		{
			if (move == COMPUTER)	//Simulate the Moves taken by Computer till the Game is Over.
			{
				best = INT_MIN;	//Start the Best Score as the Least Value possible as we have to Maximize the Score for Computer.

				for (int i = 1; i <= (SIZE * SIZE); i++)
				{
					if (check_cell (board, i) == SUCCESS)		//If the Cell position is empty, it will be Marked by the Computer.
					{
						mark_board (board, marker, i);		//To mark the 'i' with the 'marker' on the Board.
						marker = change_marker (marker);	//To update the Marking for the next Move by the User.

						/* Recursive Function call to simulate the Next Move taken by the User */
						score = calculate_score (board, marker, (move_count + 1), USER);

						/* This is a Back-Tracking Algorithm, so the Board shall be returned to the state it was before the Function call */
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
					if (check_cell (board, i) == SUCCESS)		//If the Cell position is empty, it will be Marked by the User.
					{
						mark_board (board, marker, i);		//To mark the 'i' with the 'marker' on the Board.
						marker = change_marker (marker);	//To update the Marking for the next Move by the Computer.

						/* Recursive Function call to simulate the Next Move taken by the Computer */
						score = calculate_score (board, marker, (move_count + 1), COMPUTER);

						/* This is a Back-Tracking Algorithm, so the Board shall be returned to the state it was before the Function call */
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
