#ifndef PIECE_H
#define PIECE_H
#include "../Position.h"
#include "../../Defs.h"
#include <string>

class Piece {
public:
    std::string path  = " ";
    virtual ~Piece() = default;
    explicit Piece(bool isWhite, Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]);
    virtual bool isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition) = 0;
    void setPosition(Piece* board[BOARD_SIZE][BOARD_SIZE], Position newPosition);
    bool clearPath(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition);
    bool isWhite;
    Position pos;
    bool first = true;
};

#endif //PIECE_H
