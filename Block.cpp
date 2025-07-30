#include "Block.h"

#include "Board.h"

namespace Tetris {
    Block::Block(const int& xPosition, const int& yPosition, const Color& color) {
        Reset(xPosition, yPosition, color);
    }

    void Block::Update() {
        if(m_OccupyCellOnBoard) return;

        m_HasMovedX = false;
        m_HasMovedY = false;

        if(m_MoveDownTimer <= 0.f) {
            m_MoveDownTimer = m_MoveDownInterval;
            for(int i = 0; i < 4; i++) {
                m_PossibleNextPositionArr[i].Update(m_PositionArr[i].x, m_PositionArr[i].y + GameConstants::CELL_SIZE);
            }
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
        for(int i = 0; i < 4; i++) {
            m_PossibleNextPositionArr[i].y = m_PositionArr[i].y + (GameConstants::CELL_SIZE * inputVector.y);
            m_PossibleNextPositionArr[i].x = m_PositionArr[i].x + (GameConstants::CELL_SIZE * inputVector.x);
        }

        if(inputVector.x != 0) m_HasMovedX = true;
        if(inputVector.y != 0) m_HasMovedY = true;
    }

    void Block::UpdatePosition() {
        if(m_OccupyCellOnBoard) return;
        for(int i = 0; i < 4; i++) {
            m_PositionArr[i].Update(m_PossibleNextPositionArr[i]);
        }
        UpdateIndex();
    }

    void Block::Draw() {
        if(m_OccupyCellOnBoard) return;

        for(int i = 0; i < 4; i++) {
            if(!m_IsVisibleArr[i]) continue;
            DrawRectangle(m_PositionArr[i].x, m_PositionArr[i].y, GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, m_Color);
            DrawRectangleLines(m_PositionArr[i].x, m_PositionArr[i].y, GameConstants::CELL_SIZE, GameConstants::CELL_SIZE, RAYWHITE);
        }
    }

    bool Block::HasMoved() const {
        if(m_HasMovedX || m_HasMovedY) {
            return true;
        }
        return false;
    }

    std::array<Vector2Int, 4>& Block::GetPossibleNextPositionArr() {
        return m_PossibleNextPositionArr;
    }

    const std::array<Vector2Int, 4>& Block::GetPositionArr() const {
        return m_PositionArr;
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
        for(int i = 0; i < 4; i++) {
            m_RowIndexArr[i] = Board::GetRowIndexFromPosition(m_PositionArr[i].y);
            m_ColumnIndexArr[i] = Board::GetColumnIndexFromPosition(m_PositionArr[i].x);
            if(!m_IsVisibleArr[i]) {
                m_IsVisibleArr[i] = m_RowIndexArr[i] >= Board::VISIBLE_CELL_START_ROW;
            }
        }
    }

    void Block::Reset(const int& xPosition, const int& yPosition, const Color& color) {
        int index = 0;
        for(int y = 0; y < 2; y++) {
            for(int x = 0; x < 2; x++) {
                m_PositionArr[index] = Vector2Int {xPosition + (x * GameConstants::CELL_SIZE), yPosition + (y * GameConstants::CELL_SIZE)};
                m_PossibleNextPositionArr[index] = m_PositionArr[index];
                index++;
            }
        }
        m_Color = Color(color.r, color.g, color.b, color.a);
        ResetFlags();
        ResetTimers();
        UpdateIndex();
    }

    void Block::ResetTimers() {
        m_HasLandedTimer = 0.F;
        m_MoveDownTimer = 0.F;
    }

    void Block::ResetFlags() {
        for(int i = 0; i < 4; i++) {
            m_IsVisibleArr[i] = false;
        }
        m_OccupyCellOnBoard = false;
        m_HasMovedX = false;
        m_HasMovedY = false;
        m_HasLanded = false;
    }
}