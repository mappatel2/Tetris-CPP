#pragma once

#include <memory>
#include "TetrisCore.h"
#include "TetrisBlock.h"
#include "array"

namespace Tetris {
    class BlockFactoryManager {

        using Matrix4x4 = std::array<std::array<bool, 4>, 4>;
        using RotationStateArray = std::array<Matrix4x4, 4>;

        constexpr bool BaseIBlock[4][4] = {
            {false, false, false, false},
            {true, true, true, true},
            {false, false, false, false},
            {false, false, false, false}
        };

        constexpr bool BaseJBlock[4][4] = {
            {true, false, false, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        };

        constexpr bool BaseLBlock[4][4] = {
            {false, false, true, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        };

        constexpr bool BaseOBlock[4][4] = {
            {false, false, false, false},
            {false, true, true, false},
            {false, true, true, false},
            {false, false, false, false}
        };

        constexpr bool BaseSBlock[4][4] = {
            {false, true, true, false},
            {true, true, false, false},
            {false, false, false, false},
            {false, false, false, false}
        };

        constexpr bool BaseTBlock[4][4] = {
            {false, true, false, false},
            {true, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        };

        constexpr bool BaseZBlock[4][4] = {
            {true, true, false, false},
            {false, true, true, false},
            {false, false, false, false},
            {false, false, false, false}
        };

        RotationStateArray GenerateRotations(const bool baseRotation[4][4]);

        constexpr RotationStateArray IBlockRotations = GenerateRotations(BaseIBlock);
        constexpr RotationStateArray JBlockRotations = GenerateRotations(BaseJBlock);
        constexpr RotationStateArray LBlockRotations = GenerateRotations(BaseLBlock);
        constexpr RotationStateArray OBlockRotations = GenerateRotations(BaseOBlock);
        constexpr RotationStateArray SBlockRotations = GenerateRotations(BaseSBlock);
        constexpr RotationStateArray TBlockRotations = GenerateRotations(BaseTBlock);
        constexpr RotationStateArray ZBlockRotations = GenerateRotations(BaseZBlock);

        constexpr std::array<RotationStateArray, 7> MasterRotations = {
            IBlockRotations, JBlockRotations, LBlockRotations, OBlockRotations, SBlockRotations,
            TBlockRotations, ZBlockRotations
        };

    public:
        BlockFactoryManager();
        ~BlockFactoryManager();
        [[nodiscard]] std::unique_ptr<TetrisBlock> GetTetrisBlock(const TetrominoType& blockType) const;
    };
}

