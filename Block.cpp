#include "Block.h"
#include "TetrisCore.h"
#include <iostream>

#include "BlockFactoryManager.h"
#include "Board.h"

namespace Tetris {

    void Block::Init(const TetrominoType blockType, const int xPosition, const int yPosition) {

        m_BlockType = blockType;
        m_Color = Graphics::GetTetrominoColor(m_BlockType);
        m_CornerPosition.Update(xPosition, yPosition);
        m_CurrentRotationStateIndex = 0;
        UpdateCurrentBlockPositions();

        int index = 0;
        for(int y = 0; y < 2; y++) {
            for(int x = 0; x < 2; x++) {
                m_PossibleNextPositionArr[index] = m_PositionArr[index];
                index++;
            }
        }

        ResetFlags();
        ResetTimers();
        UpdateIndex();
    }

    void Block::UpdateCurrentBlockPositions() {
        int index = 0;
        Vector2Int blockPosition = m_CornerPosition;
        const auto& rotationStateMatrix = BlockFactoryManager::GetRotationStateMatrix(m_BlockType, m_CurrentRotationStateIndex);
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(rotationStateMatrix[i][j]) {
                    blockPosition.x = m_CornerPosition.x + Config::CELL_SIZE * j;
                    blockPosition.y = m_CornerPosition.y + Config::CELL_SIZE * i;
                    m_PositionArr[index].Update(blockPosition);
                    index++;
                    if(index == 4) return;
                }
            }
        }
    }

    void Block::UpdateNextBlockPositions() {
        m_CurrentRotationStateIndex++;
        m_CurrentRotationStateIndex %= 4;
        UpdateCurrentBlockPositions();
    }

    void Block::Update() {
        if(m_OccupyCellOnBoard) return;

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

    void Block::UpdateNextPosition(const Vector2Int movementVector) {
        if(m_OccupyCellOnBoard) return;
        for(int i = 0; i < 4; i++) {
            m_PossibleNextPositionArr[i].y = m_PositionArr[i].y + (Config::CELL_SIZE * movementVector.y);
            m_PossibleNextPositionArr[i].x = m_PositionArr[i].x + (Config::CELL_SIZE * movementVector.x);
        }
    }

    void Block::MoveBy(const Vector2Int moveVector) {
        if(m_OccupyCellOnBoard) return;

        Vector2Int movePosition = moveVector;
        movePosition *= Config::CELL_SIZE;

        m_CornerPosition += movePosition;
        for(int i = 0; i < 4; i++) {
            m_PositionArr[i] += movePosition;
        }
        UpdateIndex();
    }

    void Block::Draw() {
        if(m_OccupyCellOnBoard) return;

        for(int i = 0; i < 4; i++) {
            if(!m_IsVisibleArr[i]) continue;
            DrawRectangle(m_PositionArr[i].x, m_PositionArr[i].y, Config::CELL_SIZE, Config::CELL_SIZE, m_Color);
            DrawRectangleLines(m_PositionArr[i].x, m_PositionArr[i].y, Config::CELL_SIZE, Config::CELL_SIZE, RAYWHITE);
        }
    }

    std::array<Vector2Int, 4> Block::GetPossibleNextPositionArr() const {
        return m_PossibleNextPositionArr;
    }

    std::array<Vector2Int, 4> Block::GetPositionArr() const {
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
            m_RowIndexArr[i] = GridConfig::GetRowIndexFromPosition(m_PositionArr[i].y);
            m_ColumnIndexArr[i] = GridConfig::GetColumnIndexFromPosition(m_PositionArr[i].x);
            if(!m_IsVisibleArr[i]) {
                m_IsVisibleArr[i] = m_RowIndexArr[i] >= Config::VISIBLE_CELL_START_ROW;
            }
        }
    }

    void Block::ResetTimers() {
        m_HasLandedTimer = 0.F;
    }

    void Block::ResetFlags() {
        for(int i = 0; i < 4; i++) {
            m_IsVisibleArr[i] = false;
        }
        m_OccupyCellOnBoard = false;
        m_HasLanded = false;
    }

    Color Block::GetColor() const {
        return m_Color;
    }
}