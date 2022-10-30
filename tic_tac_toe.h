#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define SIZE 3
#define FIRST 'O'
#define SECOND 'X'
#define COMPUTER 1
#define USER 2
#define SUCCESS 0
#define FAILURE -1

/* Function Declarations */

void play_game ();

void run_tests ();

void play_game_single (int);
int optimized_move (char [SIZE][SIZE], char, int);
int calculate_score (char [SIZE][SIZE], char, int, int);

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

void play_game_double ();

#endif
