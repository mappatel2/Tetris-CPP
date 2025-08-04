#pragma once

#include "TetrisBlock.h"
#include <memory>

namespace Tetris{
    class TetrisBlockFactory {
    public:
        virtual std::unique_ptr<TetrisBlock> GetBlock() = 0;
        virtual ~TetrisBlockFactory() = default;
    };
}
