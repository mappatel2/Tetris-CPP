#pragma once
#include <memory>
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"
#include "BlockFactoryManager.h"
#include "PreviewBlockUI.h"

namespace Tetris {
    class Game {
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;
        std::unique_ptr<Block> m_Block;
        std::unique_ptr<PreviewBlockUI> m_PreviewBlockUI;

        Vector2Int m_InputVector{};
        Vector2Int m_TempPosition{};

        bool m_CanSpawn = false;

        float m_SpawnTimer = 0.F;
        const float m_SpawnInterval = 0.5F;

        std::array<int, 4> m_PreviewBag;
        std::array<int, 7> m_Bag = {0, 1, 2, 3, 4, 5, 6};
        int m_CurrentShuffledBlockIndex = 0;

    public:
        Game();
        void Run();
        void Update();
        void Render();
        void Stop();

    private:
        void UpdateBlockPosition();
        void SetBlockHasLandedStatus();

        void UpdateInput();
        void UpdateBlock();
        void UpdateBoard();
        void InitBlock();

        void InitPreviewBag();
        void ShuffleTetrisBlockBag();
        [[nodiscard]] int GetBlockFromShuffledBag();
        [[nodiscard]] int GetBlockFromPreviewBag();
        [[nodiscard]] TetrominoType GetTetrisBlock();
    };
}
