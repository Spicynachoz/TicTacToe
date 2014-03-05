#ifndef TICTACTOE_H
#define TICTACTOE_H

// Defining private and public variables for Class TicTacToe
class TicTacToe
{
private:
    int pos[9];             // Which position on the board
    int player;             // Who's turn is it? ( Player 1 or 0 )
    int totalTurns;         // Number of turns in game
    int numberPlayers;      // number of players for the game (2). will edit later on for more players ( C-4)
    bool playerType[2];    // Type of player. player 1 = human, player 0 = computer
public:
    TicTacToe();
    void printTurn();
    bool playerHuman();
    void playerMove();
    void compMove();
    void drawBoard();
    bool Winner();
    bool fullBoard();
    void nextTurn();

};

#endif
