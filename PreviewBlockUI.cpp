#include "PreviewBlockUI.h"

#include "Board.h"
#include "Game.h"
#include "TetrisCore.h"

namespace Tetris {
    void PreviewBlockUI::Draw() {
        DrawRectangle(Board::GetColumnPositionFromIndex(Board::COLUMN_COUNT + 2),
            Board::GetRowPositionFromIndex(Board::VISIBLE_CELL_START_ROW - 1),
            8 * Config::CELL_SIZE,
            21 * Config::CELL_SIZE,
            YELLOW);
    }
}