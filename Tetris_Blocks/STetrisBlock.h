#pragma once
#include "../TetrisBlock.h"

namespace Tetris {
    class STetrisBlock : public TetrisBlock{
    public:
        STetrisBlock();
        ~STetrisBlock() override = default;
    };
}
