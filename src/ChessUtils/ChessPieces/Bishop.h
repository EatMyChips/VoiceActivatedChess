#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    explicit Bishop(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) override;
};

#endif //BISHOP_H
