#pragma once
#include "../TetrisBlockFactory.h"
#include "../TetrisBlock.h"
#include "TTetrisBlock.h"

namespace Tetris {
    class TTetrisBlockFactory : public TetrisBlockFactory {
    public:
        std::unique_ptr<TetrisBlock> GetBlock() override {
            return std::make_unique<TTetrisBlock>();
        }
        ~TTetrisBlockFactory() override = default;
    };
}

