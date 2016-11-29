#ifndef AI_H
#define AI_H

#include <iostream>

using namespace std;

struct Move
{
    int col, row;
};

const char player = 'x'; //Human
const char opponent = 'o'; //Computer

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool isMovesLeft(char b[3][3]);

// This is the evaluation function(heurisitcs)
int evaluate(char b[3][3]);

// This is the alpha-beta pruning function
int alphabeta(char board[3][3], int depth, int alpha, int beta, bool isMax);

#endif // AI_H
