#include "Knight.h"

Knight::Knight(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]) : Piece(isWhite, position, board) {
    if(isWhite) {
        this->path = "knight_w.png";
    }
    else {
        this->path = "knight_b.png";
    }
}

bool Knight::isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition) {
return ((board[newPosition.x][newPosition.y] && board[newPosition.x][newPosition.y]->isWhite != this->isWhite) || !board[newPosition.x][newPosition.y])
    && (((newPosition.x == this->pos.x + 1 || newPosition.x == this->pos.x - 1) && (newPosition.y == this->pos.y + 2 || newPosition.y == this->pos.y - 2))
    || ((newPosition.x == this->pos.x + 2 || newPosition.x == this->pos.x - 2) && (newPosition.y == this->pos.y + 1 || newPosition.y == this->pos.y - 1)));
}
