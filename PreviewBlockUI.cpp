#include "PreviewBlockUI.h"

#include "Board.h"
#include "Game.h"
#include "TetrisCore.h"

namespace Tetris {
    void PreviewBlockUI::Draw() const {
        DrawRectangle(GridConfig::GetColumnPositionFromIndex(m_Anchor.x),
            GridConfig::GetRowPositionFromIndex(m_Anchor.y),
            m_Columns * Config::CELL_SIZE,
            m_Rows * Config::CELL_SIZE,
            YELLOW);
    }
}