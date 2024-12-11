#ifndef TESTING_H
#define TESTING_H
#include "ChessUtils/Game.h"
#include <iostream>

class Testing {
public:
    void testInputs();
    void printBoard(Piece* board[BOARD_SIZE][BOARD_SIZE]);
    Game *game = new Game();

};

#endif //TESTING_H
