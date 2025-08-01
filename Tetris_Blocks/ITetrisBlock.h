#pragma once
#include "../TetrisBlock.h"

namespace Tetris {
    class ITetrisBlock : public TetrisBlock{
    public:
        ITetrisBlock();
        ~ITetrisBlock() override = default;
    };
}

