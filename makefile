tic_tac_toe.out : main.o board.o computer.o double_player.o minimax.o single_player.o test.o
	gcc main.o board.o computer.o double_player.o minimax.o single_player.o test.o -o tic_tac_toe.out
main.o : main.c
	gcc -c main.c
board.o : board.c
	gcc -c board.c
computer.o : computer.c
	gcc -c computer.c
double_player.o : double_player.c
	gcc -c double_player.c
minimax.o : minimax.c
	gcc -c minimax.c
single_player.o : single_player.c
	gcc -c single_player.c
test.o : test.c
	gcc -c test.c
clean :
	rm *.o *.out
