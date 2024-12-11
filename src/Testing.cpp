#include "Testing.h"

void Testing::testInputs(){
    this->printBoard(this->game->board);
    this->game->playerTurn({3,3}, {2,2}, true);
    std::cout << std::endl;
    this->printBoard(this->game->board);
}

void Testing::printBoard(Piece *board[ BOARD_SIZE][ BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(this->game->board[j][i] == nullptr) {
                std::cout << "x ";
            }
            else {
                if(this->game->board[j][i]->isWhite) {
                    std::cout << "w ";
                }
                else {
                    std::cout << "b ";
                }
            }
        }
        std::cout << std::endl;
    }
}




