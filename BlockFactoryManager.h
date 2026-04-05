#pragma once

#include "TetrisCore.h"
#include "Vector2Int.h"
#include "array"

namespace Tetris {
    class BlockFactoryManager {
    public:
        using ShapeOffsets = std::array<Vector2Int, 4>;
        using RotationStateArray = std::array<ShapeOffsets, 4>;

    private:

        static inline constexpr ShapeOffsets BaseIBlock = {{
            {0, 1}, {1, 1}, {2, 1}, {3,1}
        }};

        // static inline constexpr Matrix4x4 BaseIBlock = {{
        //     {false, false, false, false},
        //     {true,  true,  true,  true },
        //     {false, false, false, false},
        //     {false, false, false, false}
        // }};

        static inline constexpr Matrix4x4 JBlock = {{
            {true, false, false, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        }};

        static inline constexpr Matrix4x4 LBlock = {{
            {false, false, true, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        }};

        static inline constexpr Matrix4x4 OBlock ={{
            {false, false, false, false},
            {false, true, true, false},
            {false, true, true, false},
            {false, false, false, false}
        }};

        static inline constexpr Matrix4x4 SBlock = {{
            {false, true, true, false},
            {true, true, false, false},
            {false, false, false, false},
            {false, false, false, false}
        }};

        static inline constexpr Matrix4x4 ZBlock = {{
            {true, true, false, false},
            {false, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        }};

        static inline constexpr Matrix4x4 TBlock = {{
            {false, true, false, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        }};

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

        static inline constexpr RotationStateArray IBlockRotations = GenerateRotations(BaseIBlock);
        static const RotationStateArray JBlockRotations;
        static const RotationStateArray LBlockRotations;
        static const RotationStateArray OBlockRotations;
        static const RotationStateArray SBlockRotations;
        static const RotationStateArray TBlockRotations;
        static const RotationStateArray ZBlockRotations;

        static inline constexpr std::array<RotationStateArray, 7> MasterRotations = {
            IBlockRotations,
        };

    public:

        static constexpr const Matrix4x4& GetRotationStateMatrix(TetrominoType blockType, int stateIndex) {
            int blockIndex = static_cast<int>(blockType);
            return MasterRotations[blockIndex][stateIndex];
        };
    };
}

