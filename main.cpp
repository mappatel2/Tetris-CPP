#include "Game.h"
#include "TetrisCore.h"
#include "raylib.h"
#include "Vector2Int.h"
#include <array>

int main()
{
    std::array<Tetris::Vector2Int, 4> positions = {{
        {0,1}, {1, 1}, {2, 1}, {3, 1}
    }};

    std::array<std::array<Tetris::Vector2Int, 4>, 4> rotations = {};
    for (int i = 0; i < 4; i++) {
        rotations[0][i] = positions[i];
    }

    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tetris::Vector2Int position = rotations[i-1][j];
            Tetris::Vector2Int updatedPosition = {3 - position.y, position.x};
            rotations[i][j] = updatedPosition;
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << rotations[i][j] << " ";
        }
        std::cout  << "\n";
    }

    // InitWindow(Tetris::Config::SCREEN_WIDTH, Tetris::Config::SCREEN_HEIGHT, "Tetris");
    // Tetris::Game game = Tetris::Game();
    // while(!WindowShouldClose()) {
    //     BeginDrawing();
    //     ClearBackground(BLACK);
    //
    //     game.Run();
    //     EndDrawing();
    // }
    // game.Stop();
    // CloseWindow();
    return 0;
}

