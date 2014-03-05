/*Started :   2/3/2014
Last Edit : 2/15/2014
David Ye  CSCI 235 Professor Kose
Project 1 : Tic Tac Toe
Build a Tic-Tac-Toe game for Human vs Computer
Check for Winner and Tie Games.
Will include algorthim later on for smart AI & expand TTT to C-4 game.
*/

#include <iostream>
#include "TicTacToe.h"
using namespace std;
// include standard libraries and namespace
int main()
{
    // welcome message for player
    cout << " Welcome to Tic Tac Toe! " << endl << " Board is setup from 1 to 9 " << endl << " Player 1 is Human, Player 2 is the Computer"
    <<endl<< " GAME ON!" << endl;
    TicTacToe Game;
    Game.drawBoard();

    do
    {

        Game.printTurn();

        if (Game.playerHuman()) // check for human turn or computer turn
            Game.playerMove();
        else
            Game.compMove();

        Game.drawBoard();
        Game.nextTurn();
            // print board after each turn
    }
    while (!Game.Winner() && !Game.fullBoard()); // continue until Winner or tie game

    return 0;
}
