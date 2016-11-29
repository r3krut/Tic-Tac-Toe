#include "board.h"

Board::Board()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board_[i][j] = '_'; //This is empty cell
}

void Board::clear()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board_[i][j] = '_'; //empty cell
}
