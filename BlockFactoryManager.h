#pragma once

#include "TetrisCore.h"
#include "Vector2Int.h"
#include "array"

namespace Tetris {
    class BlockFactoryManager {
    public:
        using PositionOffsets = std::array<Vector2Int, 4>;
        using RotationStateArray = std::array<PositionOffsets, 4>;

    private:

        static const PositionOffsets BaseIBlock;
        static const PositionOffsets BaseJBlock;
        static const PositionOffsets BaseLBlock;
        static const PositionOffsets BaseOBlock;
        static const PositionOffsets BaseSBlock;
        static const PositionOffsets BaseZBlock;
        static const PositionOffsets BaseTBlock;

        static RotationStateArray GenerateRotations(PositionOffsets baseRotation);

        static const RotationStateArray IBlockRotations;
        static const RotationStateArray JBlockRotations;
        static const RotationStateArray LBlockRotations;
        static const RotationStateArray OBlockRotations;
        static const RotationStateArray SBlockRotations;
        static const RotationStateArray TBlockRotations;
        static const RotationStateArray ZBlockRotations;

        static const std::array<RotationStateArray, 7> MasterRotations;

    public:

        static const PositionOffsets& GetRotationStateMatrix(TetrominoType blockType, int stateIndex);
    };
}

