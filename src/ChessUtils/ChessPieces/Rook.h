#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece {
public:
    explicit Rook(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) override;
};

#endif //ROOK_H
