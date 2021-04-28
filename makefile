CC = g++
CFLAGS = -Wall -g -std=c++11

TicTacToe: game.o tictactoe.o
	$(CC) -o Tic-Tac-Toe game.o tictactoe.o
clean: 
	rm *.o