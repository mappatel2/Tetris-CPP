#pragma once
#include "GameConstants.h"
#include <array>

namespace Tetris {

    class TetrominoBlock {
    public:

        TetrominoBlock(const GameConstants::ColorType&, const std::array<std::array<std::array<bool, 4>, 4>,4>& matrix);
        const std::array<std::array<bool, 4>, 4>& GetCurrentRotationMatrix() const;
        const std::array<std::array<bool, 4>, 4>& GetNextRotationMatrix();
        const GameConstants::ColorType& GetColorType() const;

    private:

        GameConstants::ColorType m_ColorType;
        int m_CurrentRotationMatrixIndex = 0;
        std::array<std::array<std::array<bool, 4>, 4>, 4> m_RotationMatrixArr{};

    };

}
