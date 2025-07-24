#pragma once
#include <memory>
#include "Board.h"
#include "InputHandler.h"
#include "Block.h"

namespace Tetris {
    class Game {
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;
        std::unique_ptr<Block> m_Block;

        Vector2Int m_InputVector{};
        Vector2Int m_TempPosition{};

        int m_Left = 0;
        int m_Right = 0;
        int m_Down = 0;

        int m_OutlineXPosition;
        int m_OutlineYPosition;
        int m_OutlineWidth;
        int m_OutlineHeight;

    public:
        Game();
        void Run();
        void Update();
        void Render();
        void Stop();

    private:
        void UpdateBlockPosition() const;
        void SetBlockHasLandedStatus();
    };
}
