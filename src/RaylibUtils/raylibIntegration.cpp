#include "raylibIntegration.h"
#include "Renderer.h"

void runGame() {
    InitRaylib(game->board);
    while(!WindowShouldClose()) {
        pressButtom(false);
        //Render the game
        renderGame(game->board, false);
    }
    deactivateRaylib();
}

void pressButtom(bool whiteTurn) {
    Vector2 mousePos = GetMousePosition();
    mousePosition.x = (mousePos.x * BOARD_SIZE) / SCREEN_SIZE;
    mousePosition.y =(mousePos.y * BOARD_SIZE) / SCREEN_SIZE;
    if(IsMouseButtonPressed(0)) {
        if(mousePosition.x == selectedPosition.x && mousePosition.y == selectedPosition.y) {
            selectedPosition = {-1, -1};  // Deselect if clicked on the same position
        }
        else if(selectedPosition.x != -1 && selectedPosition.y != -1){
            // If a valid piece is selected, make a move
            game->playerTurn(selectedPosition, mousePosition, whiteTurn);
            selectedPosition = {-1, -1};
        }
        else {
            selectedPosition = mousePosition; // Select new piece
        }
    }
}

