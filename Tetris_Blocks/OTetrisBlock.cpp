#include "OTetrisBlock.h"

namespace Tetris {
    OTetrisBlock::OTetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {false, false, false, false},
                {false, true, true, false},
                {false, true, true, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::Yellow;
    }

}