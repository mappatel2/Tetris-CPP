#pragma once

#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "OTetrisBlock.h"

namespace Tetris {
    class OTetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<OTetrisBlock>();
        }
        ~OTetrisBlockFactory() override = default;
    };
}

