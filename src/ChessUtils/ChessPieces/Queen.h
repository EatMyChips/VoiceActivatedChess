#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    explicit Queen(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) override;
};

#endif //QUEEN_H