#include "BlockFactoryManager.h"

namespace Tetris {

    const bool BlockFactoryManager::BaseIBlock[4][4] = {
        {false, false, false, false},
        {true, true, true, true},
        {false, false, false, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseJBlock[4][4] = {
        {true, false, false, false},
        {true, true, true, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseLBlock[4][4] = {
        {false, false, true, false},
        {true, true, true, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseOBlock[4][4] = {
        {false, false, false, false},
        {false, true, true, false},
        {false, true, true, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseSBlock[4][4] = {
        {false, true, true, false},
        {true, true, false, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseTBlock[4][4] = {
        {false, true, false, false},
        {true, true, true, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    const bool BlockFactoryManager::BaseZBlock[4][4] = {
        {true, true, false, false},
        {false, true, true, false},
        {false, false, false, false},
        {false, false, false, false}
    };

    BlockFactoryManager::RotationStateArray BlockFactoryManager::GenerateRotations(const bool baseRotation[4][4]) {
        RotationStateArray states = {};
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                states[0][r][c] = baseRotation[r][c];
            }
        }

        for(int i = 1; i < 4; i++) {
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    states[i][c][3-r] = states[i-1][r][c];
                }
            }
        }
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

    const BlockFactoryManager::Matrix4x4& BlockFactoryManager::GetRotationStateMatrix(const TetrominoType blockType, const int stateIndex) {
        int blockIndex = static_cast<int>(blockType);
        return MasterRotations[blockIndex][stateIndex];
    };
}