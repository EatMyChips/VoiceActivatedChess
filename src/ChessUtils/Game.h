#ifndef GAME_H
#define GAME_H
#include "ChessPieces/Piece.h"
#include "ChessPieces/Queen.h"
#include "ChessPieces/Pawn.h"
#include "ChessPieces/Rook.h"
#include "ChessPieces/Bishop.h"
#include "ChessPieces/Knight.h"

class Game {
public:
    Game();
    Piece* board[BOARD_SIZE][BOARD_SIZE]{};
    bool playerTurn(Position piecePos, Position movePos, bool whiteMove);
    void createPieces();
    bool bInCheck;
    bool wInCheck;
    Knight* wKing;
    Knight* bKing;
};

#endif //GAME_H
