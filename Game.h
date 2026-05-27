#pragma once

#include <memory>
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"
#include "BlockSpawner.h"
#include "PreviewBlockUI.h"
#include "DebugPanelUI.h"

namespace Tetris {
    class Game {
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;
        std::unique_ptr<Block> m_Block;
        std::unique_ptr<BlockSpawner> m_BlockSpawner;
        std::unique_ptr<PreviewBlockUI> m_PreviewBlockUI;
        std::unique_ptr<DebugPanelUI> m_DebugPanel;

        Vector2Int m_MovementVector{};

        bool m_WantsToRotate = false;

        float m_MoveDownTimer = 0.f;
        const float m_MoveDownInterval = 0.8f;

        bool m_CanSpawn = false;
        float m_SpawnTimer = 0.F;
        const float m_SpawnInterval = 0.5F;

        const int m_LockResetLimit = 15;
        int m_LockResets = 0;

        float m_HasLandedTimer = 0.f;
        const float m_HasLandedInterval = 0.7F;
        bool m_HasLanded = false;

        bool m_OccupyCellOnBoard = false;

        int m_LowestRowReached = 100;

        bool m_EnableDebugPanel = false;

    public:
        Game();
        void Run();
        void Update();
        void Render();
        void Stop();

    private:

        void InitBlock();
        void UpdateInput();
        void UpdateGravity();
        void UpdateBlock();
        void SetBlockHasLandedStatus();
        void UpdateBoard();
        void UpdateLowestRowReached();
        void UpdateGhostPosition() const;
        void RenderDebugPanel() const;

    };
}
