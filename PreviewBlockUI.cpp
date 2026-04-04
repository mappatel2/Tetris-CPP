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
        int startY = m_Anchor.y + 2;

        for(const auto block : previewBag) {
            const auto blockType = static_cast<TetrominoType>(block);
            const auto blockRotationState = BlockFactoryManager::GetRotationStateMatrix(blockType, 0);
            for(int row = 0; row < 4; row++) {
                bool occupiedRow = false;
                for(int col = 0; col < 4; col++) {
                    if(blockRotationState[row][col]) {
                        int posX = GridConfig::GetColumnPositionFromIndex(startX + col);
                        int posY = GridConfig::GetRowPositionFromIndex(startY);
                        Color blockColor = Graphics::GetTetrominoColor(blockType);
                        DrawRectangle(posX, posY, Config::CELL_SIZE, Config::CELL_SIZE, blockColor);
                        DrawRectangleLines(posX, posY, Config::CELL_SIZE, Config::CELL_SIZE, DARKGRAY);
                        occupiedRow = true;
                    }
                }
                if(occupiedRow) startY++;
            }
            startY++;
        }
    }
}