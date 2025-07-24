#include "Block.h"

#include "Board.h"

namespace Tetris {
    Block::Block(const int& xPosition, const int& yPosition, const Color& color) {
        m_Position = Vector2Int {xPosition, yPosition};
        m_Color = Color(color.r, color.g, color.b, color.a);
        m_PossibleNextPosition = m_Position;
        m_IsVisible = false;
        UpdateIndex();
    }

    void Block::Update() {
        if(m_OccupyCellOnBoard) return;

        m_HasMovedX = false;
        m_HasMovedY = false;

        if(m_MoveDownTimer <= 0.f) {
            m_MoveDownTimer = m_MoveDownInterval;
            m_PossibleNextPosition.Update(m_Position.x, m_Position.y + GameConstants::CELL_SIZE);
            m_HasMovedY = true;
        }
        else {
            m_MoveDownTimer -= GetFrameTime();
        }

        if(m_HasLanded) {
            if(m_HasLandedTimer < m_HasLandedInterval) {
                m_HasLandedTimer += GetFrameTime();
            }
            else {
                m_HasLandedTimer = 0.F;
                m_OccupyCellOnBoard = true;
                std::cout << "Has Landed Timer Ended\n";
            }
        }
    }

    void Block::UpdateNextPosition(const Vector2Int& inputVector) {
        if(m_OccupyCellOnBoard) return;

        m_PossibleNextPosition.y = m_Position.y + (GameConstants::CELL_SIZE * inputVector.y);
        m_PossibleNextPosition.x = m_Position.x + (GameConstants::CELL_SIZE * inputVector.x);
        if(inputVector.x != 0) m_HasMovedX = true;
        if(inputVector.y != 0) m_HasMovedY = true;
    }

    void Block::UpdatePosition() {
        if(m_OccupyCellOnBoard) return;

        m_Position.Update(m_PossibleNextPosition);
        UpdateIndex();
    }

    void Block::Draw() {
        if(m_OccupyCellOnBoard || !m_IsVisible) return;

        DrawRectangle(m_Position.x, m_Position.y, GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, m_Color);
        DrawRectangleLines(m_Position.x, m_Position.y, GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, RAYWHITE);
    }

    bool Block::HasMoved() const {
        if(m_HasMovedX || m_HasMovedY) {
            return true;
        }
        return false;
    }

    Vector2Int& Block::GetPossibleNextPosition() {
        return m_PossibleNextPosition;
    }

    const Vector2Int& Block::GetPosition() const {
        return m_Position;
    }

    void Block::SetHasLanded(const bool hasLanded) {
        if(!m_HasLanded && hasLanded) {
            std::cout << "Landed Timer Started\n";
        }
        m_HasLanded = hasLanded;
    }

    bool Block::HasOccupiedCellOnBoard() const {
        return m_OccupyCellOnBoard;
    }

    void Block::UpdateIndex() {
        m_RowIndex = Board::GetRowIndexFromPosition(m_Position.y);
        m_ColumnIndex = Board::GetColumnIndexFromPosition(m_Position.x);
        if(!m_IsVisible) {
            m_IsVisible = m_RowIndex >= Board::VISIBLE_CELL_START_ROW;
            std::cout << "Is Visible Status : " << m_IsVisible << "\n";
        }
    }
}
