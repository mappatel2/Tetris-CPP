#include "PreviewBlockUI.h"

#include "Board.h"
#include "Game.h"
#include "TetrisCore.h"

namespace Tetris {
    void PreviewBlockUI::Draw(const std::array<int,4>& previewBag) const {
        DrawRectangleLines(GridConfig::GetColumnPositionFromIndex(m_Anchor.x),
            GridConfig::GetRowPositionFromIndex(m_Anchor.y),
            m_Columns * Config::CELL_SIZE,
            m_Rows * Config::CELL_SIZE,
            YELLOW);

        int startX = m_Anchor.x + 2;
        int startY = m_Anchor.y + 1;

        for(const auto block : previewBag) {
            const auto blockType = static_cast<TetrominoType>(block);
            const auto positionOffsets = BlockFactoryManager::GetRotationStateMatrix(blockType, 0);

            int maxY = startY;

            for (int i = 0; i < 4; i++) {
                Vector2Int positionOffset = positionOffsets[i];
                int posX = GridConfig::GetColumnPositionFromIndex(startX + positionOffset.x);
                int posY = GridConfig::GetRowPositionFromIndex(startY + positionOffset.y);
                maxY = std::max(maxY, startY + positionOffset.y);
                Color blockColor = Graphics::GetTetrominoColor(blockType);
                DrawRectangle(posX, posY, Config::CELL_SIZE, Config::CELL_SIZE, blockColor);
                DrawRectangleLines(posX, posY, Config::CELL_SIZE, Config::CELL_SIZE, DARKGRAY);
            }

            startY = maxY + 2;
        }
    }
}