#pragma once
#include "GameConstants.h"
#include <array>
#include <vector>

#include "Vector2Int.h"

namespace Tetris {

    class TetrisBlock {
    public:

        TetrisBlock() = delete;
        void GetCurrentBlockPositions(const Vector2Int& cornerPosition, std::array<Vector2Int, 4>& blockPositions) const;
        void GetNextBlockPositions(const Vector2Int& cornerPosition, std::array<Vector2Int, 4>& blockPositions);
        const GameConstants::ColorType& GetColorType() const;
        virtual ~TetrisBlock() = default;

    protected:

        GameConstants::ColorType m_ColorType;
        int m_CurrentRotationMatrixIndex = 0;
        std::vector<std::vector<std::vector<bool>>> m_RotationMatrixArr;

    };

}
