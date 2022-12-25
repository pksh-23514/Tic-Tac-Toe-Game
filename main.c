#include "tic_tac_toe.h"

/* Main function */
int main (int argc, char* argv [])
{
	if (argc < 2)			//If there are No arguments passed in the Command Line; proceed for starting the Game.
	{
		play_game ();
	}
	else				//If '--test' option is passed in the Command Line; proceed for testing the various functionalities.
	{
		run_tests ();
	}

	return 0;
}

/*
   To Execute the Tic-Tac-Toe game in Single or Double Player Mode.
   Input - NIL.
   Output - NIL.
 */
void play_game ()
{
	int choice;		//To read the User's Choice.
	char move;		//To store the First Move taken.
	do
	{
		printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t TIC-TAC-TOE\n");
		printf("\n---------------------------------------------------------------------------------------------------------------\n");
		printf("1. YOU vs COMPUTER\n");
		printf("2. USER-1 vs USER-2\n");
		printf("3. EXIT");
		printf("\n---------------------------------------------------------------------------------------------------------------\n");
		printf ("INPUT: Enter your Choice: ");
		scanf ("%d", &choice);

		switch (choice)
		{
			case 1:		/* Single Player Option */
				{
					printf ("INFO: Do you want to take the First Move : Y / N ?\n");
					printf ("INPUT: Enter your Choice: ");
					scanf (" %c", &move);

					if (toupper (move) == 'Y')	//If the User takes the First chance to play.
					{
						printf ("INFO: The First move will be taken by the USER.\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						play_game_single (USER);
					}
					else				//If the User doesn't takes the First chance to play.
					{
						printf ("INFO: The First move will be taken by the COMPUTER.\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						play_game_single (COMPUTER);
					}
				}
				break;
			case 2:		/* Double Player Option */
				{
					printf ("INFO: Does USER-1 wants to take the First Move : Y / N?\n");
					printf ("INPUT: Enter your Choice: ");
					scanf (" %c", &move);

					if (toupper (move) == 'Y')  	//If the User-1 takes the First chance to play.
					{
						printf ("INFO: The First move will be taken by the USER-1.\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						play_game_double (USER1);
					}
					else                		//If the User-1 doesn't takes the First chance to play.
					{
						printf ("INFO: The First move will be taken by the USER-2.\n");
						printf("---------------------------------------------------------------------------------------------------------------\n");
						play_game_double (USER2);
					}

				}
				break;
			case 3:		/* Exit the Game */
				{
					printf("\n---------------------------------------------------------------------------------------------------------------\n");
					printf ("\t\t\t\t\t\t THANK YOU!\n");
				}
				break;
			default: printf ("\nWrong Choice!\n");
		}

	} while (choice != 3);

	printf("---------------------------------------------------------------------------------------------------------------\n");

	return;
}
