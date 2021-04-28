/*  Author: Brandan Cavender
    Desc: Declares the TicTacToe class.
    Date: 03/21/2021 */

class TicTacToe {
    public: 
        /*  Initializes the board. */
        TicTacToe();
        /*  Runs the game. */
        void playGame(); 
    private:
        /*  Array representation of the tic-tac-toe board. */ 
        char board[3][3];
        /*  Clears the tic-tac-toe board. */
        void clearBoard();
        /*  Clears the terminal. */
        void clearTerminal();
        /*  Prints the tic-tac-toe board. */
        void printBoard();
        /*  Gets the coordinate from the player. */
        int getXCoord();
        /*  Gets the coordinate from the player. */
        int getYCoord();
        /*  Attempt to try and place a marker. If invalid return false.*/
        bool place(int, int, char);
        /*  Check if the given player has won. */
        bool victorious(char);
};
