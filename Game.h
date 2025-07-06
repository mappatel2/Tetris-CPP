#pragma once
#include <memory>
#include "Board.h"
#include "InputHandler.h"

namespace Tetris {
    class Game {
    private:

        std::unique_ptr<Board> m_Board;
        std::unique_ptr<InputHandler> m_InputHandler;

        int m_Left = 0;
        int m_Right = 0;
        int m_Down = 0;

    public:
        void Start();
        void Run();
        void Update();
        void Render();
        void Stop();
    };
}
