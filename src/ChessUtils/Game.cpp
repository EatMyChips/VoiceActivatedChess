#include "Game.h"

Game::Game() {
    createPieces();
}

bool Game::playerTurn(Position piecePos, Position movePos, bool whiteMove) {
    Piece* currentPiece = this->board[piecePos.x][piecePos.y];
    if (!currentPiece || currentPiece->isWhite != whiteMove || !currentPiece->isValidMove(this->board, movePos))
        return false;
    currentPiece->setPosition(this->board, movePos);
    if(!whiteMove) {
        wInCheck = currentPiece->isValidMove(this->board, wKing->pos);
    }
    else {
        bInCheck = currentPiece->isValidMove(this->board, bKing->pos);
    }
    return true;
}

void Game::createPieces() {
    new Queen(false, {3, 0}, this->board);
    new Queen(true, {3, 7}, this->board);
    new Pawn(true, {7, 6 }, this->board);
    new Pawn(true, {6, 6 }, this->board);
    new Pawn(true, {5, 6 }, this->board);
    new Pawn(true, {4, 6 }, this->board);
    new Pawn(true, {3, 6 }, this->board);
    new Pawn(true, {2, 6 }, this->board);
    new Pawn(true, {1, 6 }, this->board);
    new Pawn(true, {0, 6 }, this->board);
    new Pawn(false, {7, 1}, this->board);
    new Pawn(false, {6, 1}, this->board);
    new Pawn(false, {5, 1}, this->board);
    new Pawn(false, {4, 1}, this->board);
    new Pawn(false, {3, 1}, this->board);
    new Pawn(false, {2, 1}, this->board);
    new Pawn(false, {1, 1}, this->board);
    new Pawn(false, {0, 1 }, this->board);
    new Rook(true, {7, 7}, this->board);
    new Rook(true, {0, 7}, this->board);
    new Rook(false, {7, 0}, this->board);
    new Rook(false, {0, 0}, this->board);
    new Bishop(true, {5, 7}, this->board);
    new Bishop(true, {2, 7}, this->board);
    new Bishop(false, {5, 0}, this->board);
    new Bishop(false, {2, 0}, this->board);
    new Knight(true, {6, 7}, this->board);
    new Knight(true, {1, 7}, this->board);
    new Knight(false, {6, 0}, this->board);
    new Knight(false, {1, 0}, this->board);
    wKing = new Knight(true, {4, 7}, this->board);
    bKing = new Knight(false, {4, 0}, this->board);
}


