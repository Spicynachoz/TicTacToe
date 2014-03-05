#include "TicTacToe.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
// include standard libraries

TicTacToe::TicTacToe() // constructor for TicTacToe class
{

    player = 1; // human player
    totalTurns = 0;       // total turns starts at 0. Increments until board is filled (tie) or game over

    // setup for new game of Tic Tac Toe
    numberPlayers = 2;
    playerType[1] = 1;  // playerType[player] is human (1)
    playerType[2] = 0;  // playerType[player] is computer (0)
        // add more players later on for C-4.
    for (int i = 0; i < 9; i++) // put all squares into an array. Label each square 1 through 9
        pos[i] = 0;

}

void TicTacToe::drawBoard()
{
    // print out Tic Tac Toe board. 9 squares, numbered 0 to 8
        cout    << endl
                << pos[0] << " | " << pos[1] << " | " << pos[2]
                << "\n--|--|--\n"
                << pos[3] << " | " << pos[4] << " | " << pos[5]
                << "\n--|--|--\n"
                << pos[6] << " | " << pos[7] << " | " << pos[8]
                << endl;

}

void TicTacToe::printTurn() // Print out statement for Human player's turn
{
    cout << "\nPlayer " << player << "'s turn.\n" << endl;
}

void TicTacToe::nextTurn()
/* if the player number is greater than the number of players, then it is player 1's turn.
Will use numberPlayers function later on for connect 4 game */
{
    totalTurns++;

    if (++player > numberPlayers)
        player = 1;
}

bool TicTacToe::playerHuman() // check for human player
{
    return playerType[player];
}

void TicTacToe::playerMove()
// function for human move. get input from user, check that number is between 0 and 8.
{

    cout << endl<< "Please choose a square (1 to 9)" << endl;
    int move;

    do
    {
        cin >> move;
        move--;     // allows user can enter 1-9 instead of 0-8
    }
    while (move < 0 || move > 8 || pos[move] != 0);

    pos[move] = player;
}

void TicTacToe::compMove()
// function for Computer move. randomize a number from 0 to 8.
{

    int move;

    do
    {
        move  = rand() % 9;
    }
    while (move < 0 || move > 8 || pos[move] != 0); // check number is between 0 and 8.

    pos[move] = player;

}

bool TicTacToe::Winner()
// checking for Tic Tac Toe winner.
{
    int board[8][3] = {{0,1,2},
                       {3,4,5},
                       {6,7,8},
                       {0,3,6},
                       {1,4,7},
                       {2,5,8},
                       {0,4,8},
                       {2,4,6}}; // winning possibilities for Tic Tac Toe including diagonals

    for (int i = 0; i < 8; i++) // scroll through all possibilities
    {
        if ((pos[board[i][0]] == pos[board[i][1]])
            && (pos[board[i][1]] == pos[board[i][2]])
            && pos[board[i][0]] != 0)
        {

            cout << "\nCongrats Player " << pos[board[i][0]]
                      <<  " wins!\n\n";
                // print winner message
            return true;
        }
    }

    return false;
}

bool TicTacToe::fullBoard()
// checking for a tie game. Tie = board filled and no winner.
{
    if (totalTurns == 9)
    {
        cout << " Tie Game! " << endl;
        return true;
    }
    else
        return false;
}
