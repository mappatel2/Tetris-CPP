#include "TTetrisBlock.h"

namespace Tetris {
    TTetrisBlock::TTetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {false, true, false, false},
                {true, true, true, false},
                {false, false, false, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {false, true, true, false},
                {false, true, false, false},
                {false, false, false, false}
            },
            {
                {false, false, false, false},
                {true, true, true, false},
                {false, true, false, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {true, true, false, false},
                {false, true, false, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::Purple;
    }
}
