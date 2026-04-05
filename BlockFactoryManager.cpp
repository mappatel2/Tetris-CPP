#include "BlockFactoryManager.h"

namespace Tetris {

    static const BlockFactoryManager::PositionOffsets BaseIBlock = {{
        {0, 1}, {1, 1}, {2, 1}, {3,1}
    }};

    static const BlockFactoryManager::PositionOffsets BaseJBlock = {{
        {0, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    static const BlockFactoryManager::PositionOffsets BaseLBlock = {{
        {2, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    static const BlockFactoryManager::PositionOffsets BaseOBlock = {{
        {1, 1}, {2, 1}, {1, 2}, {2, 2}
    }};

    static const BlockFactoryManager::PositionOffsets BasSBlock = {{
        {1, 0}, {2, 0}, {0, 1}, {1, 1}
    }};

    static const BlockFactoryManager::PositionOffsets BasTBlock = {{
        {0, 0}, {1, 0}, {1, 1}, {2, 1}
    }};

    static const BlockFactoryManager::PositionOffsets BasZBlock = {{
        {1, 0}, {0, 1}, {1, 1}, {2, 1}
    }};

    const BlockFactoryManager::RotationStateArray BlockFactoryManager::IBlockRotations = GenerateRotations(BaseIBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::JBlockRotations = GenerateRotations(BaseJBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::LBlockRotations = GenerateRotations(BaseLBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::OBlockRotations = GenerateRotations(BaseOBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::SBlockRotations = GenerateRotations(BaseSBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::TBlockRotations = GenerateRotations(BaseTBlock);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::ZBlockRotations = GenerateRotations(BaseZBlock);

    // const std::array<BlockFactoryManager::RotationStateArray, 7> BlockFactoryManager::MasterRotations = {
    //     IBlockRotations, JBlockRotations, LBlockRotations, OBlockRotations, SBlockRotations,
    //     TBlockRotations, ZBlockRotations
    // };

    // const BlockFactoryManager::Matrix4x4& BlockFactoryManager::GetRotationStateMatrix(const TetrominoType blockType, const int stateIndex) {
    //     int blockIndex = static_cast<int>(blockType);
    //     return MasterRotations[blockIndex][stateIndex];
    // };
}