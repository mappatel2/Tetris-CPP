#include "Game.h"
#include <iostream>

namespace Tetris {
    void Game::Start() {
        m_Board = std::make_unique<Board>();
    }

    void Game::Run() {
        m_Board->Update();
        m_Board->Draw();
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }
}
