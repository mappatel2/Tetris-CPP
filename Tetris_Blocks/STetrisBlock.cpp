#include "STetrisBlock.h"

namespace Tetris {
    STetrisBlock::STetrisBlock() : TetrisBlock() {
        m_RotationMatrixArr = {
            {
                {false, true, true, false},
                {true, true, false, false},
                {false, false, false, false},
                {false, false, false, false}
            },
            {
                {false, true, false, false},
                {false, true, true, false},
                {false, false, true, false},
                {false, false, false, false}
            },
            {
                {false, false, false, false},
                {false, true, true, false},
                {true, true, false, false},
                {false, false, false, false}
            },
            {
                {true, false, false, false},
                {true, true, false, false},
                {false, true, false, false},
                {false, false, false, false}
            }
        };
        m_ColorType = GameConstants::ColorType::Green;
    }
}