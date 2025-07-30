#include "Cell.h"
#include <iostream>

namespace Tetris {
    Cell::Cell(const int xPosition, const int yPosition) {
        m_OutlineColor = GetCellColor(GameConstants::ColorType::White);
        m_IsOccupied = false;
        m_Position = Vector2Int{xPosition, yPosition};
    }

    void Cell::Update() {

    }

    void Cell::Draw() {
        if(m_IsOccupied) {
            DrawRectangle(m_Position.x, m_Position.y,
                GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, m_RectColor);
        }
        DrawRectangleLines(m_Position.x, m_Position.y,
            GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, m_OutlineColor);
    }

    void Cell::SetOccupiedStatus(bool status, const GameConstants::ColorType occupiedColorType) {
        m_RectColorType = occupiedColorType;
        m_RectColor = GetCellColor(m_RectColorType);
        m_IsOccupied = status;
    }

    bool Cell::GetOccupiedStatus() const {
        return m_IsOccupied;
    }

    GameConstants::ColorType Cell::GetRectColorType() const {
        return m_RectColorType;
    }
}
