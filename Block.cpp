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
        m_KickDataPosition = {0, 0};
        UpdateCurrentBlockPositions(m_CurrentRotationStateIndex);

        int index = 0;
        for(int y = 0; y < 2; y++) {
            for(int x = 0; x < 2; x++) {
                m_PossibleNextPositionArr[index] = m_PositionArr[index];
                index++;
            }
        }

        for(int i = 0; i < 4; i++) {
            m_IsVisibleArr[i] = false;
        }

        UpdateIndex();
    }

    void Block::ExecuteHardDrop() {
        for (int i = 0; i < 4; i++) {
            Vector2Int ghostPosition = m_GhostPositionArr[i];
            m_PositionArr[i] = ghostPosition;
        }
    }

    void Block::UpdateCurrentRotationIndex() {
        m_CurrentRotationStateIndex = m_ProspectiveRotationStateIndex;
        m_CornerPosition += m_KickDataPosition;
        UpdateCurrentBlockPositions(m_CurrentRotationStateIndex);
    }

    void Block::UpdateCurrentBlockPositions(int rotationStateIndex) {
        auto positionOffsets = BlockFactoryManager::GetRotationStateMatrix(m_BlockType, rotationStateIndex);
        for (int i = 0; i < 4; i++) {
            Vector2Int blockPosition = GridConfig::IndexToScreenPosition(positionOffsets[i]) + m_CornerPosition;
            m_PositionArr[i] = blockPosition;
        }
    }

    void Block::UpdateNextRotationIndex(int kickTestIndex) {
        m_ProspectiveRotationStateIndex = m_CurrentRotationStateIndex + 1;
        m_ProspectiveRotationStateIndex %= 4;

        Vector2Int kickDataOffset = BlockFactoryManager::GetKickOffset(m_BlockType, m_ProspectiveRotationStateIndex, kickTestIndex);
        m_KickDataPosition = GridConfig::IndexToScreenPosition(kickDataOffset);

        auto positionOffsets = BlockFactoryManager::GetRotationStateMatrix(m_BlockType, m_ProspectiveRotationStateIndex);
        for (int i = 0; i < 4; i++) {
            Vector2Int blockPosition = GridConfig::IndexToScreenPosition(positionOffsets[i]) + m_CornerPosition + m_KickDataPosition;
            m_PossibleNextPositionArr[i] = blockPosition;
        }
    }

    void Block::UpdateNextPosition(const Vector2Int movementVector) {
        for(int i = 0; i < 4; i++) {
            m_PossibleNextPositionArr[i] = m_PositionArr[i] + (Config::CELL_SIZE * movementVector);
        }
    }

    void Block::MoveBy(const Vector2Int moveVector) {
        Vector2Int movePosition = moveVector;
        movePosition *= Config::CELL_SIZE;

        m_CornerPosition += movePosition;
        for(int i = 0; i < 4; i++) {
            m_PositionArr[i] += movePosition;
        }
        UpdateIndex();
    }

    void Block::UpdateGhostPosition(const std::array<Vector2Int, 4>& ghostPositionArr) {
        for (int i = 0; i < 4; i++) {
            m_GhostPositionArr[i] = ghostPositionArr[i];
        }
    }

    void Block::Draw() {
        auto ghostPieceColor = RAYWHITE;
        ghostPieceColor.a = 75;
        for(int i = 0; i < 4; i++) {
            DrawRectangle(m_GhostPositionArr[i].x, m_GhostPositionArr[i].y, Config::CELL_SIZE, Config::CELL_SIZE, ghostPieceColor);
            if(!m_IsVisibleArr[i]) continue;
            DrawRectangle(m_PositionArr[i].x, m_PositionArr[i].y, Config::CELL_SIZE, Config::CELL_SIZE, m_Color);
            DrawRectangleLines(m_PositionArr[i].x, m_PositionArr[i].y, Config::CELL_SIZE, Config::CELL_SIZE, RAYWHITE);
        }
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

    std::array<Vector2Int, 4> Block::GetPossibleNextPositionArr() const {
        return m_PossibleNextPositionArr;
    }

    std::array<Vector2Int, 4> Block::GetGhostPositionArr() const {
        return m_GhostPositionArr;
    }

    std::array<Vector2Int, 4> Block::GetPositionArr() const {
        return m_PositionArr;
    }

    Color Block::GetColor() const {
        return m_Color;
    }

    int Block::GetRotationStateIndex() const {
        return m_CurrentRotationStateIndex;
    }

    TetrominoType Block::GetBlockType() const {
        return m_BlockType;
    }
}