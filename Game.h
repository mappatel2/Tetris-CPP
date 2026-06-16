#pragma once

#include <memory>
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"
#include "BlockSpawner.h"
#include "PreviewBlockUI.h"
#include "DebugPanelUI.h"
#include "IGameState.h"
#include "ScoreHelper.h"
#include "ScorePanelUI.h"

namespace Tetris {
    class Game{
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;
        std::unique_ptr<Block> m_Block;
        std::unique_ptr<BlockSpawner> m_BlockSpawner;

        std::unique_ptr<PreviewBlockUI> m_PreviewBlockUI;
        std::unique_ptr<DebugPanelUI> m_DebugPanel;
        std::unique_ptr<ScorePanelUI> m_ScorePanelUI;

        std::unique_ptr<ScoreHelper> m_ScoreHelper;

        std::array<std::unique_ptr<IGameState>, 2> m_GameStates{};
        GameState m_GameState = GameState::GameOver;
        IGameState* m_CurrentState{};

    private:
        void InitGameStates();

    public:
        Game();
        void Run();
        void Update();
        void Render();
        void Stop();
        void ChangeGameState(GameState newGameState);
    };
}
