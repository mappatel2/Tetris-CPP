#pragma once

#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "JTetrisBlock.h"

namespace Tetris {
    class JTetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<JTetrisBlock>();
        }
        ~JTetrisBlockFactory() override = default;
    };
}

