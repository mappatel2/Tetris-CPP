#pragma once
#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "STetrisBlock.h"

namespace Tetris {
    class STetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<STetrisBlock>();
        }
        ~STetrisBlockFactory() override = default;
    };
}

