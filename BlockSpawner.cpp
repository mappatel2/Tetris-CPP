#include "BlockSpawner.h"

namespace Tetris {
    BlockSpawner::BlockSpawner() {
        ShuffleTetrisBlockBag();
        m_PreviewBag = {0, 0, 0, 0};
        for(int i = 0; i < 4; i++) {
            m_PreviewBag[i] = GetBlockFromShuffledBag();
        }
    }

    int BlockSpawner::GetBlockFromShuffledBag() {
        if(m_CurrentShuffledBlockIndex >= m_Bag.size()) {
            ShuffleTetrisBlockBag();
        }
        return m_Bag[m_CurrentShuffledBlockIndex++];
    }

    int BlockSpawner::GetBlockFromPreviewBag() {
        int blockIndex = m_PreviewBag[0];
        int nextBlockInShuffledBag = GetBlockFromShuffledBag();
        for(int i = 0; i < 3; i++) {
            m_PreviewBag[i] = m_PreviewBag[i+1];
        }
        m_PreviewBag[3] = nextBlockInShuffledBag;
        return blockIndex;
    }

    void BlockSpawner::ShuffleTetrisBlockBag() {
        m_CurrentShuffledBlockIndex = 0;
        for(int i = m_Bag.size() - 1; i >= 0; i--) {
            int randomIndex = GetRandomValue(0, i);
            std::swap(m_Bag[i], m_Bag[randomIndex]);
        }
    }

    TetrominoType BlockSpawner::GetTetrisBlock() {
        int blockInPreviewBag = GetBlockFromPreviewBag();
        return static_cast<TetrominoType>(blockInPreviewBag);
    }

    std::array<int, 4> BlockSpawner::GetPreviewBag() const {
        return m_PreviewBag;
    }
}
