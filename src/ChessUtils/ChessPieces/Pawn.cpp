#include "Pawn.h"

Pawn::Pawn(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]) : Piece(isWhite, position, board) {
    if(isWhite) {
        this->path = "pawn_w.png";
    }
    else {
        this->path = "pawn_b.png";
    }
}

bool Pawn::isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition) {
    bool moveForward;
    bool diagonalTake;
    if(this->isWhite) {
        moveForward = (!board[newPosition.x][this->pos.y - 1] && !board[newPosition.x][this->pos.y - 1 - this->first])
                        && ((this->pos.x == newPosition.x && this->pos.y == newPosition.y + 1 + this->first) || (this->pos.x == newPosition.x && this->pos.y == newPosition.y + 1));
        diagonalTake = ((board[newPosition.x][newPosition.y] && board[newPosition.x][newPosition.y]->isWhite != this->isWhite) && (this->pos.x == newPosition.x - 1 && this->pos.y == newPosition.y + 1 || this->pos.x == newPosition.x + 1 && this->pos.y == newPosition.y + 1));
    }
    else {
        moveForward = (!board[newPosition.x][this->pos.y + 1] && !board[newPosition.x][this->pos.y + 1 + this->first])
                        && ((this->pos.x == newPosition.x && this->pos.y == newPosition.y - 1 - this->first) || (this->pos.x == newPosition.x && this->pos.y == newPosition.y - 1));
        diagonalTake = ((board[newPosition.x][newPosition.y] && board[newPosition.x][newPosition.y]->isWhite != this->isWhite) && (this->pos.x == newPosition.x - 1 && this->pos.y == newPosition.y - 1 || this->pos.x == newPosition.x + 1 && this->pos.y == newPosition.y - 1));
    }
    return moveForward || diagonalTake;
}