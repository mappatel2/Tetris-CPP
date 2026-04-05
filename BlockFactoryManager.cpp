#include "BlockFactoryManager.h"

namespace Tetris {

    // const BlockFactoryManager::RotationStateArray BlockFactoryManager::IBlockRotations = GenerateRotations(BaseIBlock);
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