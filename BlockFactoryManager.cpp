#include "BlockFactoryManager.h"
#include "TetrisBlock.h"

namespace Tetris {
    BlockFactoryManager::BlockFactoryManager() {
        m_IBlockFactory = std::make_unique<ITetrisBlockFactory>();
        m_JBlockFactory = std::make_unique<JTetrisBlockFactory>();
        m_LBlockFactory = std::make_unique<LTetrisBlockFactory>();
        m_OBlockFactory = std::make_unique<OTetrisBlockFactory>();
        m_SBlockFactory = std::make_unique<STetrisBlockFactory>();
        m_TBlockFactory = std::make_unique<TTetrisBlockFactory>();
        m_ZBlockFactory = std::make_unique<ZTetrisBlockFactory>();
        ShuffleTetrisBlockBag();
    }

    void BlockFactoryManager::ShuffleTetrisBlockBag() {
        m_CurrentBlockIndex = 0;
        for(int i = m_Bag.size() - 1; i >= 0; i--) {
            int randomIndex = GetRandomValue(0, i);
            std::swap(m_Bag[i], m_Bag[randomIndex]);
        }
    }

    std::unique_ptr<TetrisBlock> BlockFactoryManager::GetTetrisBlock() {
        if(m_CurrentBlockIndex >= m_Bag.size()) {
            ShuffleTetrisBlockBag();
        }
        return GetTetrisBlock(m_BlockTypesArr[m_Bag[m_CurrentBlockIndex++]]);
    }

    std::unique_ptr<TetrisBlock> BlockFactoryManager::GetTetrisBlock(const BlockType& blockType) const {
        switch(blockType) {
            case IBlock:
                return m_IBlockFactory->GetBlock();
            case JBlock:
                return m_JBlockFactory->GetBlock();
            case LBlock:
                return m_LBlockFactory->GetBlock();
            case OBlock:
                return m_OBlockFactory->GetBlock();
            case SBlock:
                return m_SBlockFactory->GetBlock();
            case TBlock:
                return m_TBlockFactory->GetBlock();
            case ZBlock:
            default:
                return m_ZBlockFactory->GetBlock();
        }
    }

    BlockFactoryManager::~BlockFactoryManager() {
        m_IBlockFactory.reset();
        m_JBlockFactory.reset();
        m_LBlockFactory.reset();
        m_OBlockFactory.reset();
        m_SBlockFactory.reset();
        m_TBlockFactory.reset();
        m_ZBlockFactory.reset();
    }
}