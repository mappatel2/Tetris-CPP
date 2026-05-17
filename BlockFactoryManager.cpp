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

    BlockFactoryManager::RotationStateArray BlockFactoryManager::GenerateRotations(PositionOffsets baseRotation, int gridSize){
        RotationStateArray states = {};
        for (int i = 0; i < 4; i++) {
            states[0][i] = baseRotation[i];
        }

        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int oldX = states[i-1][j].x;
                int oldY = states[i-1][j].y;

                int newX = (gridSize - 1) - oldY;
                int newY = oldX;
                states[i][j] = {newX, newY};
            }
        }

        return states;
    }

    const BlockFactoryManager::RotationStateArray BlockFactoryManager::IBlockRotations = GenerateRotations(BaseIBlock, 4);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::JBlockRotations = GenerateRotations(BaseJBlock, 3);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::LBlockRotations = GenerateRotations(BaseLBlock, 3);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::OBlockRotations = GenerateRotations(BaseOBlock, 4);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::SBlockRotations = GenerateRotations(BaseSBlock, 3);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::TBlockRotations = GenerateRotations(BaseTBlock, 3);
    const BlockFactoryManager::RotationStateArray BlockFactoryManager::ZBlockRotations = GenerateRotations(BaseZBlock,3);

    const std::array<BlockFactoryManager::RotationStateArray, 7> BlockFactoryManager::MasterRotations = {
        IBlockRotations, JBlockRotations, LBlockRotations, OBlockRotations, SBlockRotations,
        TBlockRotations, ZBlockRotations
    };

    BlockFactoryManager::PositionOffsets BlockFactoryManager::GetRotationStateMatrix(const TetrominoType blockType, const int stateIndex) {
        int blockIndex = static_cast<int>(blockType);
        return MasterRotations[blockIndex][stateIndex];
    };

    const BlockFactoryManager::KickDataMatrix BlockFactoryManager::CommonKickData ={{
        // Transition From 0 -> 1
        {{ {0, 0}, {-1, 0}, {-1, -1}, {0,  2}, {-1,  2} }},

        // Transition From 1 -> 2
        {{ {0, 0}, { 1, 0}, { 1,  1}, {0, -2}, { 1, -2} }},

        // Transition From 2 -> 3
        {{ {0, 0}, { 1, 0}, { 1, -1}, {0,  2}, { 1,  2} }},

        // Transition From 3 -> 0
        {{ {0, 0}, {-1, 0}, {-1,  1}, {0, -2}, {-1, -2} }}
    }};

    const BlockFactoryManager::KickDataMatrix BlockFactoryManager::IKickData = {{
        // Transition From 0 -> 1
        {{ {0, 0}, {-2, 0}, { 1, 0}, {-2,  1}, { 1, -2} }},

        // Transition From 1 -> 2
        {{ {0, 0}, {-1, 0}, { 2, 0}, {-1, -2}, { 2,  1} }},

        // Transition From 2 -> 3
        {{ {0, 0}, { 2, 0}, {-1, 0}, { 2, -1}, {-1,  2} }},

        // Transition From 3 -> 0
        {{ {0, 0}, { 1, 0}, {-2, 0}, { 1,  2}, {-2, -1} }}
    }};

    Vector2Int BlockFactoryManager::GetKickOffset(TetrominoType blockType, int rotationStateIndex, int kickTestIndex) {
        switch (blockType) {
            case TetrominoType::O:
                return {0, 0};
            case TetrominoType::I:
                return IKickData[rotationStateIndex][kickTestIndex];
            default:
                return CommonKickData[rotationStateIndex][kickTestIndex];
        }
    }
}