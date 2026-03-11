#include "TetrisBlock.h"

namespace Tetris {
    void TetrisBlock::GetCurrentBlockPositions(const Vector2Int &cornerPosition,
        std::array<Vector2Int, 4> &blockPositions) const {
        int index = 0;
        Vector2Int blockPosition = cornerPosition;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(m_RotationMatrixArr[m_CurrentRotationMatrixIndex][i][j]) {
                    blockPosition.x = cornerPosition.x + Config::CELL_SIZE * j;
                    blockPosition.y = cornerPosition.y + Config::CELL_SIZE * i;
                    blockPositions[index].Update(blockPosition);
                    index++;
                    if(index == 4) return;
                }
            }
        }
    }

    void TetrisBlock::GetNextBlockPositions(const Vector2Int &cornerPosition,
        std::array<Vector2Int, 4> &blockPositions) {
        m_CurrentRotationMatrixIndex++;
        if(m_CurrentRotationMatrixIndex >= m_RotationMatrixArr.size()) m_CurrentRotationMatrixIndex = 0;
        GetCurrentBlockPositions(cornerPosition, blockPositions);
    }

    const Graphics::ColorType& TetrisBlock::GetColorType() const {
        return m_ColorType;
    }
}
