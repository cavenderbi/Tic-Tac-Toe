/*  Author: Brandan Cavender
    Desc: Main Tic-Tac-Toe class.
    Date: 03/21/2021 */

#include "tictactoe.h"
#include <iostream>
using namespace std;

/*  Game constructor. */
TicTacToe::TicTacToe() {
    clearBoard();
}
/*  Game loop. Basically the actual game. */
void TicTacToe::playGame() {
    char p1 = 'X';
    char p2 = 'O';
    char curPlayer = p1; 
    bool gameOver = false;
    int x, y;
    int turn = 0;
    /*  While the game has yet to be won, keep going. */
    while (!gameOver) {
        printBoard();
        x = getXCoord();
        y = getYCoord();
        /*  Place markers. */
        if(!place(x, y, curPlayer)) {
            cout << "That spot is occupied!" << endl;
        } else {
            turn++;
            /*  Check for victory conditions. */
            if (victorious(curPlayer)) {
                clearTerminal();
                printBoard();
                cout << "Game Over! " << curPlayer << " won!" << endl;
                gameOver = true;
            }
            else if (turn == 9) {
                cout << "Game Tied." << endl;
                gameOver = true;
            }
            else clearTerminal();
            /*  Swap players. */
            if (curPlayer == p1) curPlayer = p2;
            else curPlayer = p1;
        }
    }
}
/*  Clears the tic-tac-toe board. */
void TicTacToe::clearBoard() {
    for (auto& rows : board)
        for (auto& elem : rows)
            elem = ' ';
}
/*  Clears the terminal. */
void TicTacToe::clearTerminal() {
    system("clear");
}
/*  Prints the tic-tac-toe board. */
void TicTacToe::printBoard() {
    cout << endl;
    cout << " |0 1 2|" << endl;
    for (int i = 0; i < 3; i++) {
        cout << " -------\n";
        cout << i << '|' << board[i][0] << '|' << board[i][1] << '|' << board[i][2] << '|' << endl;
    }
    cout << " -------\n";
}
/*  Gets the X coordinate from the player. */
int TicTacToe::getXCoord() {
    int x;
    cout << "Enter your X coordinate:";
    cin >> x;
    return x;
}
/*  Gets the Y coordinate from the player. */
int TicTacToe::getYCoord() {
    int y;
    cout << "Enter your Y coordinate:";
    cin >> y;
    return y;
}
bool TicTacToe::place(int x, int y, char c) {
    if (board[y][x] != ' ') 
        return false;
    board[y][x] = c;
    return true;
}
bool TicTacToe::victorious(char p) {
    /*  Check the rows. */
    for (int i = 0; i < 3; i++) 
        if ((board[i][0] == p) && (board[i][1] == p) && (board[i][2] == p))
            return true;
    /*  Check the columns. */
    for (int i = 0; i < 3; i++) 
        if ((board[0][i] == p) && (board[1][i] == p) && (board[2][i] == p))
            return true;
    /*  Check foward diagonal. */
    if ((board[0][0] == p) && (board[1][1] == p) && (board[2][2] == p))
        return true;
    /*  Check back diagonal. */
    if ((board[0][2] == p) && (board[1][1] == p) && (board[2][0] == p))
        return true;
    return false;
}