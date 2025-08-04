#pragma once

#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "LTetrisBlock.h"

namespace Tetris {
    class LTetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<LTetrisBlock>();
        }
        ~LTetrisBlockFactory() override = default;
    };
}

