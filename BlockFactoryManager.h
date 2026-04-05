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

        static inline constexpr RotationStateArray GenerateRotations(const Matrix4x4 baseRotation) {
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

        static const RotationStateArray IBlockRotations;
        static const RotationStateArray JBlockRotations;
        static const RotationStateArray LBlockRotations;
        static const RotationStateArray OBlockRotations;
        static const RotationStateArray SBlockRotations;
        static const RotationStateArray TBlockRotations;
        static const RotationStateArray ZBlockRotations;

        static const std::array<RotationStateArray, 7> MasterRotations;

    public:

        static const Matrix4x4& GetRotationStateMatrix(TetrominoType blockType, int stateIndex) {
            int blockIndex = static_cast<int>(blockType);
            return MasterRotations[blockIndex][stateIndex];
        };
    };
}

