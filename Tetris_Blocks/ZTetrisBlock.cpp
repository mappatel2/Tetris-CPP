#include "ZTetrisBlock.h"

namespace Tetris {
    ZTetrisBlock::ZTetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {true, true, false, false},
                {false, true, true, false},
                {false, false, false, false},
                {false, false, false, false}
            },
            {
                {false, false, true, false},
                {false, true, true, false},
                {false, true, false, false},
                {false, false, false, false}
            },
            {
                {false, false, false, false},
                {true, true, false, false},
                {false, true, true, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {true, true, false, false},
                {true, false, false, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::Red;
    }
}
