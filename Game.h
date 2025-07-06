#pragma once
#include <memory>
#include "Board.h"

namespace Tetris {
    class Game {
    private:
        std::unique_ptr<Board> m_Board;

    public:
        void Start();
        void Run();
        void Stop();
    };
}
