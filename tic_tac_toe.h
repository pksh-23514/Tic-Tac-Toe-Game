#ifndef MAIN_H
#define MAIN_H

/* Standard Libraries Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/* MACRO Definitions */
#define SIZE 		3
#define FIRST 		'O'
#define SECOND 		'X'
#define COMPUTER 	1
#define USER 		2
#define USER1 		1
#define USER2 		2
#define SUCCESS 	0
#define FAILURE 	-1

/* Function Declarations */

/* Play the Tic-Tac-Toe Game in the selected Player Mode */
void play_game ();

/* Unit-Testing */
void run_tests ();

/* Single Player Mode */
void play_game_single (int);
int optimized_move (char [SIZE][SIZE], char, int);
int calculate_score (char [SIZE][SIZE], char, int, int);

/* Board Operations */
void initialize_board (char [SIZE][SIZE]);
void print_board (char [SIZE][SIZE]);
int check_cell (char [SIZE][SIZE], int);
void mark_board (char [SIZE][SIZE], char, int);
void demark_board (char [SIZE][SIZE], int);
char change_marker (char);
int game_over (char [SIZE][SIZE]);
int row_win (char [SIZE][SIZE]);
int col_win (char [SIZE][SIZE]);
int diagonal_win (char [SIZE][SIZE]);

/* Double Player Mode */
void play_game_double (int);

#endif
