#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight : public Piece {
public:
    explicit Knight(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) override;
};

#endif //KNIGHT_H
