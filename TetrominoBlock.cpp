#include "TetrominoBlock.h"

namespace Tetris {

    TetrominoBlock::TetrominoBlock(const GameConstants::ColorType& colorType, const std::array<std::array<std::array<bool, 4>, 4>,4>& matrix) {
        m_ColorType = colorType;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    m_RotationMatrixArr[i][j][k] = matrix[i][j][k];
                }
            }
        }
    }

    const std::array<std::array<bool, 4>, 4>& TetrominoBlock::GetCurrentRotationMatrix() const{
        return m_RotationMatrixArr[m_CurrentRotationMatrixIndex];
    }

    const std::array<std::array<bool, 4>, 4> &TetrominoBlock::GetNextRotationMatrix() {
        m_CurrentRotationMatrixIndex++;
        if(m_CurrentRotationMatrixIndex >= 4) m_CurrentRotationMatrixIndex = 0;
        return GetCurrentRotationMatrix();
    }

    const GameConstants::ColorType& TetrominoBlock::GetColorType() const {
        return m_ColorType;
    }

}