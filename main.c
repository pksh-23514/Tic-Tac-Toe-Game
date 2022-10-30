#include "tic_tac_toe.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		play_game ();
	}
	else
	{
		//run_tests ();
	}

	return 0;
}
#if 1
void play_game ()
{
	int choice;
	char move;
	do
	{
		printf("\n---------------------------------------------------------------------------------------------------------------\n\n");
		printf("\t\t\t\t\t\t TIC-TAC-TOE\n");
		printf("\n---------------------------------------------------------------------------------------------------------------\n");
		printf("1. YOU vs COMPUTER\n");
		printf("2. YOU vs PLAYER\n");
		printf("3. EXIT");
		printf("\n---------------------------------------------------------------------------------------------------------------\n");
		printf ("INPUT: Enter your Choice: ");
		scanf ("%d", &choice);

		switch (choice)
		{
			case 1:
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
			case 2:
				{
					//
				}
				break;
			case 3:
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
#endif
