#include "Game.h"
#include "TetrisCore.h"
#include "raylib.h"

int main()
{
    InitWindow(Tetris::Config::SCREEN_WIDTH, Tetris::Config::SCREEN_HEIGHT, "Tetris");
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

