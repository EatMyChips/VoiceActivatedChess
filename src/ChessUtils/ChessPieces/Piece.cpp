#include "Piece.h"

Piece::Piece(bool isWhite, Position position, Piece* board[BOARD_SIZE][BOARD_SIZE]) {
    this->isWhite = isWhite;
    this->pos = position;
    board[position.x][position.y] = this;
}

void Piece::setPosition(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition) {
    board[pos.x][pos.y] = nullptr;
    this->pos = newPosition;
    board[newPosition.x][newPosition.y] = this;
    this->first = false;
}

bool Piece::clearPath(Piece* board[BOARD_SIZE][BOARD_SIZE], const Position newPosition) {
    int xIncrease = 0;
    int yIncrease = 0;
    int amountToChange = 0;
    //works out weather the x or y should be increased
    if(newPosition.x - this->pos.x > 0) {
        xIncrease = 1;
        amountToChange = newPosition.x - this->pos.x;
    }
    else if (newPosition.x - this->pos.x < 0){
        xIncrease = -1;
        amountToChange = newPosition.x - this->pos.x;
    }
    if(newPosition.y - this->pos.y > 0) {
        yIncrease = 1;
        amountToChange = newPosition.y - this->pos.y;
    }
    else if (newPosition.y - this->pos.y < 0){
        yIncrease = -1;
        amountToChange = newPosition.y - this->pos.y;
    }
    for (int i = 1; i <  std::abs(amountToChange); i++) {
        if(board[this->pos.x + i * xIncrease][this->pos.y + i * yIncrease]) {
            return false;
        }
    }
    return true;
}