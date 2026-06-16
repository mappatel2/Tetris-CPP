#include "GameOverState.h"
#include "TetrisCore.h"

namespace Tetris {
    GameOverState::GameOverState(Game* game, InputHandler* inputHandler) {
        m_Game = game;
        m_InputHandler = inputHandler;
    }

    void GameOverState::Update() {

    }

    void GameOverState::Draw() {
        DrawRectangle(0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, Color(0, 0, 0, 175));
    }

    void GameOverState::HandleInput() {

    }
}
