#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece {
public:
    explicit Pawn(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) override;
};

#endif //PAWN_H
