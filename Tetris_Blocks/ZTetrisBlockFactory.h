#pragma once
#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "ZTetrisBlock.h"

namespace Tetris {
    class ZTetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<ZTetrisBlock>();
        }
        ~ZTetrisBlockFactory() override = default;
    };
}

