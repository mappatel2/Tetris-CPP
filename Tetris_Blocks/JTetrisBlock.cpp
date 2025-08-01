#include "JTetrisBlock.h"

namespace Tetris {
    JTetrisBlock::JTetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {true, false, false, false},
                {true, true, true, false},
                {false, false, false, false},
                {false, false, false, false}
            },
            {
                {false, true, true, false},
                {false, true, false, false},
                {false, true, false, false},
                {false, false, false, false}
            },
            {
                {false, false, false, false},
                {true, true, true, false},
                {false, false, true, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {false, true, false, false},
                {true, true, false, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::Blue;
    }
}