#include "LTetrisBlock.h"

namespace Tetris {
    LTetrisBlock::LTetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {false, false, true, false},
                {true, true, true, false},
                {false, false, false, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {false, true, false, false},
                {false, true, true, false},
                {false, false, false, false}
            },
            {
                {false, false, false, false},
                {true, true, true, false},
                {true, false, false, false},
                {false, false, false, false}
            },
            {
                {true, true, false, false},
                {false, true, false, false},
                {false, true, false, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::LBlock;
    }
}