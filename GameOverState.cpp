#include "GameOverState.h"
#include "TetrisCore.h"

namespace Tetris {
    GameOverState::GameOverState(Game* game, InputHandler* inputHandler) {
        m_Game = game;
        m_InputHandler = inputHandler;
    }

    void GameOverState::OnEnter() {

    }

    void GameOverState::OnExit() {

    }

    void GameOverState::HandleInput() {
        if (m_InputHandler->CanTriggerGameRestart()) {
            std::cout << "Restart Game" << std::endl;
            m_Game->PopAndPushGameState(GameState::Playing);
        }
    }

    void GameOverState::Update() {

    }

    void GameOverState::Draw() {
        DrawRectangle(0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, Color(0, 0, 0, 175));
    }
}
