#ifndef BOARD_H
#define BOARD_H

struct Board
{
    char board_[3][3]; //game board

    Board(); //construct

    void clear(); //makes clear the game board
};

#endif // BOARD_H
