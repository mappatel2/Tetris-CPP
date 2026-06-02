#include "ScorePanelUI.h"
#include "raylib.h"
#include "TetrisCore.h"
#include "ResourceManager.h"

namespace Tetris {

    void ScorePanelUI::Draw(int score) const {
        int yPosition = GridConfig::GetRowPositionFromIndex(Config::ROW_COUNT) + (Config::CELL_SIZE / 6);
        int xPosition = GridConfig::GetColumnPositionFromIndex(Config::COLUMN_COUNT / 2) - Config::CELL_SIZE / 6;
        auto position = Vector2(static_cast<float>(xPosition), static_cast<float>(yPosition));
        DrawTextEx(ResourceManager::GetMainFont(), Tetris::ToString(score).c_str(), position, 25.F, 0.F, RAYWHITE);
    }
}
