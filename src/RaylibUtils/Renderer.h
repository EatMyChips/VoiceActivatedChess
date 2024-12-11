#ifndef RENDERER_H
#define RENDERER_H
#include <raylib.h>
#include <iostream>
#include <map>
#include <filesystem>
#include "../Defs.h"
#include "../ChessUtils/ChessPieces/Piece.h"

const int GRID_SIZE = SCREEN_SIZE / BOARD_SIZE;
void renderGame(Piece* board[BOARD_SIZE][BOARD_SIZE], bool whiteTurn);
void InitRaylib(Piece* board[BOARD_SIZE][BOARD_SIZE]);
void deactivateRaylib();
void drawBoard(Piece* board[BOARD_SIZE][BOARD_SIZE], bool whiteTurn);
using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
inline std::map<std::string, Texture2D> textures;



#endif //RENDERER_H
