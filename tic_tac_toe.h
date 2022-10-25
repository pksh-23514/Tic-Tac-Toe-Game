#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 3
#define FIRST 'O'
#define SECOND 'X'
#define COMPUTER 1
#define USER 2
#define SUCCESS 0
#define FAILURE -1

/* Function Declarations */

void play_game_single (int);

void initialize_board (char [SIZE][SIZE]);

void print_board (char [SIZE][SIZE]);

void play_game_double ();

int check_cell (char [SIZE][SIZE], int);

void mark_board (char [SIZE][SIZE], char, int);

#endif
