#include "DebugPanelUI.h"
#include "ResourceManager.h"

namespace Tetris {
    void DebugPanelUI::Draw(std::initializer_list<DebugEntry> entries) const {

        int posX = GridConfig::GetColumnPositionFromIndex(k_Anchor.x);
        int posY = GridConfig::GetRowPositionFromIndex(k_Anchor.y);
        int width = (k_Columns + 1) * Config::CELL_SIZE;
        int height = k_Rows * Config::CELL_SIZE;

        DrawRectangleLines(posX, posY, width, height, RAYWHITE);
        DrawRectangle(posX, posY, width, Config::CELL_SIZE, RAYWHITE);

        Vector2 headerSize = MeasureTextEx(ResourceManager::GetMainFont(), "DEBUG STATS", 25.F, 0.F);
        float xPos = static_cast<float>(posX) + static_cast<float>(width) / 2.F - headerSize.x / 2.F;
        auto position = Vector2(xPos, static_cast<float>(posY + 8));
        DrawTextEx(ResourceManager::GetMainFont(), "DEBUG STATS", position, 25.F, 0.F, BLACK);

        auto currentPos = Vector2(static_cast<float>(posX + 5), static_cast<float>(posY) + Config::CELL_SIZE + 5.F);
        for (const auto& entry : entries) {

            xPos = currentPos.x;
            DrawTextEx(ResourceManager::GetMainFont(), entry.label, currentPos, 25.F, 0.F, RAYWHITE);

            Vector2 labelSize = MeasureTextEx(ResourceManager::GetMainFont(), entry.label, 25.F, 0.F);
            currentPos.x += labelSize.x + 10.F;
            DrawTextEx(ResourceManager::GetMainFont(), "---", currentPos, 25.F, 0.F, RAYWHITE);

            labelSize = MeasureTextEx(ResourceManager::GetMainFont(), "---", 25.F, 0.F);
            currentPos.x += labelSize.x + 10.F;
            DrawTextEx(ResourceManager::GetMainFont(), entry.value.c_str(), currentPos, 25.F, 0.F, RAYWHITE);

            currentPos.x = xPos;
            currentPos.y += 25.F;
        }
    }
}
