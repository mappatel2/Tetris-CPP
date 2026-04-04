#pragma once
#include <memory>
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"
#include "BlockFactoryManager.h"
#include "BlockSpawner.h"
#include "PreviewBlockUI.h"

namespace Tetris {
    class Game {
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;
        std::unique_ptr<Block> m_Block;
        std::unique_ptr<BlockSpawner> m_BlockSpawner;
        std::unique_ptr<PreviewBlockUI> m_PreviewBlockUI;

        Vector2Int m_MovementVector{};

        float m_MoveDownTimer = 0.f;
        const float m_MoveDownInterval = 0.8f;

        bool m_CanSpawn = false;
        float m_SpawnTimer = 0.F;
        const float m_SpawnInterval = 0.5F;

    public:
        Game();
        void Run();
        void Update();
        void Render();
        void Stop();

    private:

        void SetBlockHasLandedStatus();

        void UpdateInput();
        void UpdateGravity();
        void UpdateBlock();
        void UpdateBoard();
        void InitBlock();

    };
}
