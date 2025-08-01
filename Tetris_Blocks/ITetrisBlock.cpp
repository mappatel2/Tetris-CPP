#include "ITetrisBlock.h"

namespace Tetris {
    ITetrisBlock::ITetrisBlock() : TetrisBlock() {

        m_RotationMatrixArr = {
            {
                {false, false, false, false},
                {true, true, true, true},
                {false, false, false, false},
                {false, false, false, false},
            },
            {
                {false, true, false, false},
                {false, true, false, false},
                {false, true, false, false},
                {false, true, false, false},
            },
            {
                {false, false, false, false},
                {false, false, false, false},
                {true, true, true, true},
                {false, false, false, false},
            },
            {
                {false, false, true, false},
                {false, false, true, false},
                {false, false, true, false},
                {false, false, true, false},
            }
        };

        m_ColorType = GameConstants::ColorType::Cyan;
    }
}
