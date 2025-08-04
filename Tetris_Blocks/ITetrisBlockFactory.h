#pragma once
#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "ITetrisBlock.h"

namespace Tetris {
    class ITetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<ITetrisBlock>();
        }
        ~ITetrisBlockFactory() override = default;
    };
}

