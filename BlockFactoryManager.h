#pragma once

#include <memory>
#include <array>

#include "Tetris_Blocks/ITetrisBlockFactory.h"
#include "Tetris_Blocks/JTetrisBlockFactory.h"
#include "Tetris_Blocks/LTetrisBlockFactory.h"
#include "Tetris_Blocks/OTetrisBlockFactory.h"
#include "Tetris_Blocks/STetrisBlockFactory.h"
#include "Tetris_Blocks/TTetrisBlockFactory.h"
#include "Tetris_Blocks/ZTetrisBlockFactory.h"

namespace Tetris {
    class BlockFactoryManager {

    private:

        std::unique_ptr<ITetrisBlockFactory> m_IBlockFactory;
        std::unique_ptr<JTetrisBlockFactory> m_JBlockFactory;
        std::unique_ptr<LTetrisBlockFactory> m_LBlockFactory;
        std::unique_ptr<OTetrisBlockFactory> m_OBlockFactory;
        std::unique_ptr<STetrisBlockFactory> m_SBlockFactory;
        std::unique_ptr<TTetrisBlockFactory> m_TBlockFactory;
        std::unique_ptr<ZTetrisBlockFactory> m_ZBlockFactory;

        enum BlockType {
            IBlock,
            JBlock,
            LBlock,
            OBlock,
            SBlock,
            TBlock,
            ZBlock
        };

        std::array<BlockType, 7> m_BlockTypesArr = {
            IBlock,
            JBlock,
            LBlock,
            OBlock,
            SBlock,
            TBlock,
            ZBlock
        };

        [[nodiscard]] std::unique_ptr<TetrisBlock> GetTetrisBlock(const BlockType& blockType) const;

    public:
        BlockFactoryManager();
        ~BlockFactoryManager();
    };
}

