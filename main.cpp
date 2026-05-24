#include "Game.h"
#include "TetrisCore.h"
#include "raylib.h"
#include "ResourceManager.h"

int main()
{
    InitWindow(Tetris::Config::SCREEN_WIDTH, Tetris::Config::SCREEN_HEIGHT, "Tetris");

    ResourceManager::LoadFont("C:/Users/mapga/CPP_Projects/Tetris/Fonts/MomoTrustDisplay-Regular.ttf");
    Tetris::Game game = Tetris::Game();

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        game.Run();
        EndDrawing();
    }

    game.Stop();
    ResourceManager::Unload();

    CloseWindow();
    return 0;
}

