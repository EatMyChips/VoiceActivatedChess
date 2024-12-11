#include "Queen.h"

Queen::Queen(const bool isWhite, const Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]) : Piece(isWhite, position, board) {
    if(isWhite) {
        this->path = "queen_w.png";
    }
    else {
        this->path = "queen_b.png";
    }

}

bool Queen::isValidMove(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition) {
    bool isMoveable = false;

    if(board[newPosition.x][newPosition.y] && board[newPosition.x][newPosition.y]->isWhite == this->isWhite) {
        return false;
    }
    //checks the position it is moved to is a valid position
    isMoveable = (newPosition.x != this->pos.x && newPosition.y == this->pos.y)
                || (newPosition.x == this->pos.x && newPosition.y != this->pos.y)
                || (newPosition.x - this->pos.x) == (newPosition.y - this->pos.y)
                || (newPosition.x - this->pos.x) == -(newPosition.y - this->pos.y);

    if(!isMoveable) {
        return false;
    }
    return clearPath(board, newPosition);
}
