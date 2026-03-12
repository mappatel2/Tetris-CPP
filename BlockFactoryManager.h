#pragma once

#include "TetrisCore.h"
#include "array"

namespace Tetris {
    class BlockFactoryManager {
    public:
        using Matrix4x4 = std::array<std::array<bool, 4>, 4>;
        using RotationStateArray = std::array<Matrix4x4, 4>;

    private:

        static const bool BaseIBlock[4][4];
        static const bool BaseJBlock[4][4];
        static const bool BaseLBlock[4][4];
        static const bool BaseOBlock[4][4];
        static const bool BaseSBlock[4][4];
        static const bool BaseTBlock[4][4];
        static const bool BaseZBlock[4][4];

        static RotationStateArray GenerateRotations(const bool baseRotation[4][4]);

        static const RotationStateArray IBlockRotations;
        static const RotationStateArray JBlockRotations;
        static const RotationStateArray LBlockRotations;
        static const RotationStateArray OBlockRotations;
        static const RotationStateArray SBlockRotations;
        static const RotationStateArray TBlockRotations;
        static const RotationStateArray ZBlockRotations;

        static const std::array<RotationStateArray, 7> MasterRotations;

    public:

        static const Matrix4x4& GetRotationStateMatrix(TetrominoType blockType, int stateIndex);
    };
}

