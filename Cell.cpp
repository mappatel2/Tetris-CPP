#include "Cell.h"
#include <iostream>

namespace Tetris {
    Cell::Cell(const bool isVisible
        , const int xPosition, const int yPosition) {
        m_IsVisible = isVisible;
        m_OutlineColorType = m_IsVisible ? GameConstants::ColorType::White : GameConstants::ColorType::Transparent;
        m_OutlineColor = GetCellColor(m_OutlineColorType);
        m_IsOccupied = false;
        m_XPosition = xPosition;
        m_YPosition = yPosition;
    }

    void Cell::Update() {

    }

    void Cell::Draw() {
        DrawRectangleLines(m_XPosition, m_YPosition,
            GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, m_OutlineColor);
        if(m_IsOccupied) {
            DrawRectangleRec(m_Rect, m_RectColor);
        }
    }

    void Cell::SetOccupied(GameConstants::ColorType occupiedColorType) {
        m_RectColorType = occupiedColorType;
        m_RectColor = GetCellColor(m_RectColorType);
        m_IsOccupied = true;
        m_Rect = Rectangle(static_cast<float>(m_XPosition), static_cast<float>(m_YPosition),
            GameConstants::CELL_SIZE, GameConstants::CELL_SIZE);
    }

    Cell::~Cell() {
        std::cout << "Cell Destroyed\n";
    }

}
