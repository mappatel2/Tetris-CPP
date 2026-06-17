#ifndef TETRIS_BLOCKSPAWNER_H
#define TETRIS_BLOCKSPAWNER_H

#include<array>
#include "TetrisCore.h"

namespace Tetris {
    class BlockSpawner {

    private:
        std::array<int, 4> m_PreviewBag{};
        std::array<int, 7> m_Bag = {0, 1, 2, 3, 4, 5, 6};
        int m_CurrentShuffledBlockIndex = 0;

    public:

        BlockSpawner();
        void Reset();
        [[nodiscard]] std::array<int, 4> GetPreviewBag() const;
        [[nodiscard]] TetrominoType GetTetrisBlock();

    private:

        void ShuffleTetrisBlockBag();
        int GetBlockFromShuffledBag();
        int GetBlockFromPreviewBag();

    };
}

#endif //TETRIS_BLOCKSPAWNER_H
