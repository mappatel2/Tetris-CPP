#include "BlockFactoryManager.h"

namespace Tetris {

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseIBlock = {{
        {0, 1}, {1, 1}, {2, 1}, {3,1}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseJBlock = {{
        {0, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseLBlock = {{
        {2, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseOBlock = {{
        {1, 1}, {2, 1}, {1, 2}, {2, 2}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseSBlock = {{
        {1, 0}, {2, 0}, {0, 1}, {1, 1}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseTBlock = {{
        {0, 0}, {1, 0}, {1, 1}, {2, 1}
    }};

    const BlockFactoryManager::PositionOffsets BlockFactoryManager::BaseZBlock = {{
        {1, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    BlockFactoryManager::RotationStateArray BlockFactoryManager::GenerateRotations(PositionOffsets baseRotation){
        RotationStateArray states = {};
        for (int i = 0; i < 4; i++) {

        }

        // for(int i = 1; i < 4; i++) {
        //     for(int r = 0; r < 4; r++) {
        //         for(int c = 0; c < 4; c++) {
        //             states[i][c][3-r] = states[i-1][r][c];
        //         }
        //     }
        // }
        return states;
    }

    const BlockFactoryManager::RotationStateArray BlockFactoryManager::IBlockRotations = GenerateRotations(BaseIBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::JBlockRotations = GenerateRotations(BaseJBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::LBlockRotations = GenerateRotations(BaseLBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::OBlockRotations = GenerateRotations(BaseOBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::SBlockRotations = GenerateRotations(BaseSBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::TBlockRotations = GenerateRotations(BaseTBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::ZBlockRotations = GenerateRotations(BaseZBlock);

    const std::array<BlockFactoryManager::RotationStateArray, 7> BlockFactoryManager::MasterRotations = {
        IBlockRotations, JBlockRotations, LBlockRotations, OBlockRotations, SBlockRotations,
        TBlockRotations, ZBlockRotations
    };

    // const BlockFactoryManager::PositionOffsets& BlockFactoryManager::GetRotationStateMatrix(const TetrominoType blockType, const int stateIndex) {
    //     int blockIndex = static_cast<int>(blockType);
    //     return MasterRotations[blockIndex][stateIndex];
    // };
}