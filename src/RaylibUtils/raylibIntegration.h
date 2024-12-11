#ifndef RAYLIBINTEGRATION_H
#define RAYLIBINTEGRATION_H
#include <string>
#include "../ChessUtils/Game.h"
#include "../ChessUtils/Position.h"

void runGame();
void pressButtom(bool whiteTurn);
inline Position mousePosition;
inline Position selectedPosition = {-1, -1};
inline Game *game = new Game();

#endif //RAYLIBINTEGRATION_H
