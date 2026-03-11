#pragma once
#include "TetrisCore.h"
#include <array>
#include <vector>

#include "Vector2Int.h"

namespace Tetris {
    class TetrisBlock {
    public:

        void GetCurrentBlockPositions(const Vector2Int& cornerPosition, std::array<Vector2Int, 4>& blockPositions) const;
        void GetNextBlockPositions(const Vector2Int& cornerPosition, std::array<Vector2Int, 4>& blockPositions);
        [[nodiscard]] const Graphics::ColorType& GetColorType() const;
        virtual ~TetrisBlock() = default;

    protected:

        TetrisBlock() = default;
        Graphics::ColorType m_ColorType{};
        int m_CurrentRotationMatrixIndex = 0;
        std::vector<std::vector<std::vector<bool>>> m_RotationMatrixArr;

    };

}
