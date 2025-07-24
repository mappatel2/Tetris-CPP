#include "Game.h"
#include "GameConstants.h"
#include "raylib.h"

int main()
{
    InitWindow(Tetris::GameConstants::SCREEN_WIDTH, Tetris::GameConstants::SCREEN_HEIGHT, "Tetris");
    Tetris::Game game = Tetris::Game();
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        game.Run();
        EndDrawing();
    }
    game.Stop();
    CloseWindow();
    return 0;
}

