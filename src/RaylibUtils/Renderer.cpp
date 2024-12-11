#include "Renderer.h"
#include "raylibIntegration.h"

void InitRaylib(Piece* board[BOARD_SIZE][BOARD_SIZE]){
    InitWindow(SCREEN_SIZE + (SCREEN_SIZE / 16), SCREEN_SIZE +(SCREEN_SIZE / 16), "Chess");

    for (const auto& dirEntry : recursive_directory_iterator("./textures")) {
        std::string path = dirEntry.path().string();
        Image image = LoadImage(path.c_str());
        ImageResize(&image, GRID_SIZE, GRID_SIZE);
        textures[dirEntry.path().filename().string()] = LoadTextureFromImage(image);
        UnloadImage(image);
    }
}

void renderGame(Piece* board[BOARD_SIZE][BOARD_SIZE], bool whiteTurn) {
    BeginDrawing();
    drawBoard(board, whiteTurn);
    //DrawFPS(0,0);
    EndDrawing();
}

void deactivateRaylib() {
    CloseWindow();
}

void drawBoard(Piece* board[BOARD_SIZE][BOARD_SIZE], bool whiteTurn) {
    ClearBackground(WHITE);
    for(int i = 0; i < BOARD_SIZE; i ++){
        for(int j = 0; j < BOARD_SIZE; j ++) {
            bool isBlue = (i % 2) == (j % 2);
            Color color = { static_cast<unsigned char>(255 * isBlue), static_cast<unsigned char>(255 * isBlue), static_cast<unsigned char>(255 * isBlue), 200 };
            if(selectedPosition.x == i && selectedPosition.y == j) {
                color = { static_cast<unsigned char>(50), static_cast<unsigned char>(200), static_cast<unsigned char>(50), 255 };
            }
            else if(mousePosition.x == i && mousePosition.y == j) {
                color = { static_cast<unsigned char>(50), static_cast<unsigned char>(150), static_cast<unsigned char>(50), 255 };
            }
            DrawRectangle(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE, color);

            if(board[i][j]) {
                std::string tmp = board[i][j]->path;
                DrawTexture(textures[board[i][j]->path],i * GRID_SIZE, j * GRID_SIZE, WHITE);
            }
            if(selectedPosition.x != -1 && board[selectedPosition.x][selectedPosition.y] && board[selectedPosition.x][selectedPosition.y]->isValidMove(board,{i, j}) && board[selectedPosition.x][selectedPosition.y]->isWhite == whiteTurn) {
                bool isRed = !board[i][j] || board[selectedPosition.x][selectedPosition.y]->isWhite == board[i][j]->isWhite;
                Color circleColor = { 190, static_cast<unsigned char>(180 * isRed), static_cast<unsigned char>(20 * isRed), 100 };
                DrawCircle(i * GRID_SIZE + (GRID_SIZE/2), j * GRID_SIZE  + (GRID_SIZE/2), GRID_SIZE / 3, circleColor);
            }
        }
    }
    for(int i = 1; i < 9; i++) {
        char temp = 'A' + (i - 1);
        DrawText(&temp, ((GRID_SIZE)* i) - (GRID_SIZE/1.8), SCREEN_SIZE + 2, SCREEN_SIZE / 15, BLACK);
        DrawText(std::to_string(i).c_str(), SCREEN_SIZE + 2  ,((GRID_SIZE)* i) - (GRID_SIZE/1.4), SCREEN_SIZE / 15, BLACK);
    }
}

