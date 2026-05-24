#include "DebugPanelUI.h"

namespace Tetris {
    void DebugPanelUI::Draw() const {

        int posX = GridConfig::GetColumnPositionFromIndex(k_Anchor.x);
        int posY = GridConfig::GetRowPositionFromIndex(k_Anchor.y);
        int width = k_Columns * Config::CELL_SIZE;
        int height = k_Rows * Config::CELL_SIZE;

        DrawRectangleLines(posX, posY, width, height, RAYWHITE);
        DrawRectangle(posX, posY, width, Config::CELL_SIZE, RAYWHITE);
    }
}
