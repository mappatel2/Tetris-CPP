#include "Game.h"
#include "GameConstants.h"
#include "raylib.h"

int main()
{
    InitWindow(Tetris::GameConstants::SCREEN_WIDTH, Tetris::GameConstants::SCREEN_HEIGHT, "Tetris");
    Tetris::Game game = Tetris::Game();
    game.Start();
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangleLines(Tetris::GameConstants::LEFT_PADDING - Tetris::GameConstants::CELL_SIZE, Tetris::GameConstants::TOP_PADDING - Tetris::GameConstants::CELL_SIZE,
            Tetris::GameConstants::CELL_SIZE * 22, Tetris::GameConstants::CELL_SIZE * 22, RAYWHITE);
        game.Run();
        EndDrawing();
    }
    game.Stop();
    CloseWindow();
    return 0;
}

