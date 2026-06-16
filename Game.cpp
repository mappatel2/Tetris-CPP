#include "Game.h"
#include <iostream>

#include "GameOverState.h"
#include "GamePlayingState.h"
#include "InputHandler.h"
#include "PreviewBlockUI.h"

namespace Tetris {
    Game::Game() {
        m_Board = std::make_unique<Board>();
        m_InputHandler = std::make_unique<InputHandler>();
        m_BlockSpawner = std::make_unique<BlockSpawner>();
        m_PreviewBlockUI = std::make_unique<PreviewBlockUI>();
        m_DebugPanel = std::make_unique<DebugPanelUI>();
        m_ScorePanelUI = std::make_unique<ScorePanelUI>();
        m_ScoreHelper = std::make_unique<ScoreHelper>();
        m_Block = std::make_unique<Block>();

        m_Board->AddObserver(m_ScoreHelper.get());
        m_Block->AddObserver(m_ScoreHelper.get());

        InitGameStates();
        ChangeGameState(GameState::Playing);
    }

    void Game::Run() {
        Update();
        Render();
    }

    void Game::Update() {
        m_CurrentState->HandleInput();
        m_CurrentState->Update();
        m_CurrentState->Draw();
    }

    void Game::Render() {
        m_Board->Draw();
        m_PreviewBlockUI->Draw(m_BlockSpawner->GetPreviewBag());
        m_ScorePanelUI->Draw(m_ScoreHelper->GetScore());
        m_CurrentState->Draw();
    }

    void Game::Stop() {
        m_Board->RemoveObserver(m_ScoreHelper.get());
        m_Block->RemoveObserver(m_ScoreHelper.get());
        m_CurrentState = nullptr;
        std::cout << "Stopping Game, Call Destroy Functions for Entities\n";
    }

    void Game::InitGameStates() {
        m_GameStates[static_cast<int>(GameState::Playing)] = std::make_unique<GamePlayingState>(this, m_InputHandler.get(),
            m_BlockSpawner.get(), m_Board.get(), m_Block.get(), m_ScoreHelper.get(), m_DebugPanel.get());

        m_GameStates[static_cast<int>(GameState::GameOver)] = std::make_unique<GameOverState>(this, m_InputHandler.get());
    }

    void Game::ChangeGameState(GameState newGameState) {
        IGameState* gameState = m_GameStates[static_cast<int>(newGameState)].get();
        if (gameState == nullptr) return;
        m_CurrentState = gameState;
    }
}
