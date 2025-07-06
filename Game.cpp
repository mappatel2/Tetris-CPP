#include "Game.h"
#include <iostream>
#include "InputHandler.h"

namespace Tetris {
    void Game::Start() {
        m_Board = std::make_unique<Board>();
        m_InputHandler = std::make_unique<InputHandler>();
    }

    void Game::Run() {
        Update();
        Render();
    }

    void Game::Update() {
        m_InputHandler->Update();
        if(m_InputHandler->CanMoveLeft()) {
            m_Left++;
            std::cout << m_Left << "\n";
        }
        if(m_InputHandler->CanMoveRight()) {
            m_Right++;
            std::cout << m_Right << "\n";
        }
        if(m_InputHandler->CanMoveDown()) {
            m_Down++;
            std::cout << m_Down << "\n";
        }

        m_Board->Update();
    }

    void Game::Render() {
        m_Board->Draw();
    }

    void Game::Stop() {
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }
}
